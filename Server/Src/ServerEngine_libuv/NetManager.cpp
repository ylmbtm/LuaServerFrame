#include "stdafx.h"
#include "NetManager.h"
#include "Connection.h"
#include "CommandDef.h"
#include "../ServerEngine/CommonConvert.h"
#include "Log.h"
#include "PacketHeader.h"
#include "DataBuffer.h"


void _Run_Loop(void* arg)
{

	CNetManager* pNetManager = (CNetManager*)arg;

	pNetManager->RunLoop();

	return;
}

void On_Async_Event(uv_async_t* handle)
{
	CConnection* pConnection = (CConnection*)handle->data;

	pConnection->DoSend();

	uv_close((uv_handle_t*)&pConnection->m_AsyncReq, NULL);

	return;
}

void On_Connection(uv_connect_t* req, int status)
{
	CConnection* pConnection = (CConnection*)req->data;

	if (status == 0)
	{
		//成功
		CNetManager::GetInstancePtr()->HandleConnect(pConnection, status);
	}
	else
	{
		//失败
		pConnection->Close();
	}

	return;
}

void On_RecvConnection(uv_stream_t* pServer, int status)
{
	if (status < 0)
	{
		//失败
		return;
	}

	CConnection* pConnection = CConnectionMgr::GetInstancePtr()->CreateConnection();
	ERROR_RETURN_NONE(pConnection != NULL);

	CNetManager* pNetManager = CNetManager::GetInstancePtr();

	uv_tcp_init(pNetManager->m_pMainLoop, pConnection->GetSocket());

	if (uv_accept(pServer, (uv_stream_t*)pConnection->GetSocket()) == 0)
	{
		pNetManager->HandleAccept(pConnection, 0);
	}
	else
	{
		pConnection->Close();
	}

	return;
}


CNetManager::CNetManager(void)
{
	m_pBufferHandler	= NULL;
}

CNetManager::~CNetManager(void)
{
}

BOOL CNetManager::Start(UINT16 nPortNum, UINT32 nMaxConn, IDataHandler* pBufferHandler, std::string& strListenIp)
{
	ERROR_RETURN_FALSE(pBufferHandler != NULL);

	m_pBufferHandler = pBufferHandler;

	CConnectionMgr::GetInstancePtr()->InitConnectionList(nMaxConn);

	if (strListenIp.empty() || strListenIp.length() < 4)
	{
		strListenIp = "0.0.0.0";
	}

	m_pMainLoop = uv_default_loop();

	uv_tcp_init(m_pMainLoop, &m_ListenSocket);

	sockaddr_in addr;

	uv_ip4_addr(strListenIp.c_str(), nPortNum, &addr);

	uv_tcp_bind(&m_ListenSocket, (const struct sockaddr*)&addr, 0);

	int nRetCode = uv_listen((uv_stream_t*)&m_ListenSocket, 20, On_RecvConnection);
	if (nRetCode)
	{
		return FALSE;
	}

	uv_thread_create(&m_LoopThreadID, _Run_Loop, this);

	return TRUE;
}

BOOL CNetManager::Stop()
{
	uv_close((uv_handle_t*)&m_ListenSocket, NULL);

	uv_stop(m_pMainLoop);
	uv_loop_close(m_pMainLoop);
	uv_thread_join(&m_LoopThreadID);

	CConnectionMgr::GetInstancePtr()->CloseAllConnection();

	CConnectionMgr::GetInstancePtr()->DestroyAllConnection();

	return TRUE;
}

void CNetManager::OnUdpAllocBuff(uv_handle_t* pHandle, size_t suggested_size, uv_buf_t* buf)
{
	CNetManager* pNetManager = (CNetManager*)uv_handle_get_data(pHandle);

	if (pNetManager->m_pUdpRecvBuffer == NULL)
	{
		pNetManager->m_pUdpRecvBuffer = CBufferAllocator::GetInstancePtr()->AllocDataBuff(RECV_BUF_SIZE);
	}

	buf->base = pNetManager->m_pUdpRecvBuffer->GetBuffer();

	buf->len = pNetManager->m_pUdpRecvBuffer->GetBufferSize();

	return;
}

void CNetManager::OnUdpReadData(uv_udp_t* handle,
                                ssize_t nread,
                                const uv_buf_t* buf,
                                const struct sockaddr* addr,
                                unsigned flags)
{
	if (nread > 0)
	{
		CNetManager* pNetManager = (CNetManager*)uv_handle_get_data((const uv_handle_t*)handle);
		if (pNetManager->m_pUdpRecvBuffer == NULL)
		{
			CLog::GetInstancePtr()->LogError("UDP_RECV失败 原因: m_pUdpRecvBuffer is NULL!");
			return;
		}

		pNetManager->m_pUdpRecvBuffer->SetTotalLenth(nread);

		PacketHeader* pHeader = (PacketHeader*)pNetManager->m_pUdpRecvBuffer->GetBuffer();
		if (pHeader->dwMsgID == 300028)
		{
			CConnection* pConnection = CConnectionMgr::GetInstancePtr()->GetConnectionByID((UINT32)pHeader->u64TargetID);
			if (pConnection == NULL)
			{
				CLog::GetInstancePtr()->LogError("UDP_RECV失败 原因: TCP 连接不存在!");
				return;
			}

			pConnection->m_UdpAddr = pNetManager->m_udpClientAddr;
		}

		pNetManager->m_pBufferHandler->OnDataHandle(pNetManager->m_pUdpRecvBuffer, 0);

		pNetManager->m_pUdpRecvBuffer = NULL;
	}

	return;
}

void CNetManager::OnUdpSend(uv_udp_send_t* pReq, int iStatus)
{

	return;
}

BOOL CNetManager::StartUdp(INT32 nUdpPort)
{
	ERROR_RETURN_FALSE(nUdpPort > 0);

	uv_udp_init(m_pMainLoop, &m_UdpSvrSocket);

	sockaddr_in svrAddr;

	uv_ip4_addr("0.0.0.0", nUdpPort, &svrAddr);

	int nError = uv_udp_bind(&m_UdpSvrSocket, (const sockaddr*)&svrAddr, UV_UDP_REUSEADDR);
	ERROR_RETURN_FALSE(nError >= 0);

	int nSockBufSize = 1024000;
	uv_recv_buffer_size((uv_handle_t*)&m_UdpSvrSocket, &nSockBufSize);

	uv_handle_set_data((uv_handle_t*)&m_UdpSvrSocket, (void*)this);

	uv_udp_recv_start(&m_UdpSvrSocket, OnUdpAllocBuff, OnUdpReadData);

	return TRUE;
}

BOOL CNetManager::StopUdp()
{
	uv_udp_recv_stop(&m_UdpSvrSocket);

	if (m_pUdpRecvBuffer != NULL)
	{
		m_pUdpRecvBuffer->Release();
		m_pUdpRecvBuffer = NULL;
	}

	return TRUE;
}

CConnection* CNetManager::ConnectTo_Sync(std::string strIpAddr, UINT16 sPort)
{
	return NULL;
}

CConnection* CNetManager::ConnectTo_Async( std::string strIpAddr, UINT16 sPort )
{
	struct sockaddr_in bind_addr;
	int iret = uv_ip4_addr(strIpAddr.c_str(), sPort, &bind_addr);
	if (iret)
	{
		return NULL;
	}

	CConnection* pConnection = CConnectionMgr::GetInstancePtr()->CreateConnection();
	if (pConnection == NULL)
	{
		return NULL;
	}

	iret = uv_tcp_init(m_pMainLoop, pConnection->GetSocket());
	pConnection->GetSocket()->data = pConnection;
	pConnection->m_ConnectReq.data = pConnection;

	iret = uv_tcp_connect(&pConnection->m_ConnectReq, pConnection->GetSocket(), (const sockaddr*)&bind_addr, On_Connection);
	if (iret)
	{
		pConnection->Close();
	}

	return pConnection;
}


void CNetManager::HandleConnect(CConnection* pConnection, INT32 dwStatus)
{
	m_pBufferHandler->OnNewConnect(pConnection->GetConnectionID());

	pConnection->DoReceive();

	return ;
}

void CNetManager::HandleAccept(CConnection* pConnection, INT32 dwStatus)
{
	if (dwStatus == 0)
	{
		m_pBufferHandler->OnNewConnect(pConnection->GetConnectionID());

		pConnection->DoReceive();
	}
	else
	{
		pConnection->Close();
		//处理错误
	}

	return;
}


void CNetManager::RunLoop()
{
	uv_run(m_pMainLoop, UV_RUN_DEFAULT);

	return;
}

BOOL	CNetManager::SendMessageBuff(UINT32 dwConnID, IDataBuffer* pBuffer)
{
	ERROR_RETURN_FALSE(dwConnID != 0);
	ERROR_RETURN_FALSE(pBuffer != 0);
	CConnection* pConn = CConnectionMgr::GetInstancePtr()->GetConnectionByID(dwConnID);
	if (pConn == NULL)
	{
		//表示连接己经失败断开了，这个连接ID不可用了。
		return FALSE;
	}
	if (!pConn->IsConnectionOK())
	{
		CLog::GetInstancePtr()->LogError("CNetManager::SendMsgBufByConnID FAILED, 连接己断开");
		return FALSE;
	}

	pBuffer->AddRef();
	if (pConn->SendBuffer(pBuffer))
	{
		PostSendOperation(pConn);
		return TRUE;
	}

	return FALSE;
}


BOOL CNetManager::SendMessageByUdp(UINT32 dwConnID, UINT32 dwMsgID, UINT64 u64TargetID, UINT32 dwUserData, const char* pData, UINT32 dwLen)
{
	if (dwConnID <= 0)
	{
		return FALSE;
	}

	CConnection* pConnection = CConnectionMgr::GetInstancePtr()->GetConnectionByID(dwConnID);
	ERROR_RETURN_FALSE(pConnection != NULL);
	/*
	CHAR szBuff[20480] = { 0 };

	PacketHeader* pHeader = (PacketHeader*)szBuff;
	pHeader->CheckCode = 0x88;
	pHeader->dwUserData = dwUserData;
	pHeader->u64TargetID = u64TargetID;
	pHeader->dwSize = dwLen + sizeof(PacketHeader);
	pHeader->dwMsgID = dwMsgID;
	pHeader->dwPacketNo = 1;

	memcpy(szBuff + sizeof(PacketHeader), pData, dwLen);

	uv_handle_set_data((uv_handle_t*)&m_udpSendReq, (void*)this);

	m_udpSendBuf.base = szBuff;
	m_udpSendBuf.len = pHeader->dwSize;

	uv_udp_send(&m_udpSendReq, &m_UdpSvrSocket, &m_udpSendBuf, 1, (struct sockaddr*)&pConnection->m_UdpAddr, OnUdpSend);
	*/
	return TRUE;
}

BOOL CNetManager::SendMessageData(UINT32 dwConnID, UINT32 dwMsgID, UINT64 u64TargetID, UINT32 dwUserData, const char* pData, UINT32 dwLen)
{
	if (dwConnID <= 0)
	{
		return FALSE;
	}

	CConnection* pConn = CConnectionMgr::GetInstancePtr()->GetConnectionByID(dwConnID);
	if (pConn == NULL)
	{
		//表示连接己经失败断开了，这个连接ID不可用了。
		return FALSE;
	}

	if (!pConn->IsConnectionOK())
	{
		CLog::GetInstancePtr()->LogError("CNetManager::SendMessageByConnID FAILED, 连接己断开");
		return FALSE;
	}

	IDataBuffer* pDataBuffer = CBufferAllocator::GetInstancePtr()->AllocDataBuff(dwLen + sizeof(PacketHeader));
	ERROR_RETURN_FALSE(pDataBuffer != NULL);

	PacketHeader* pHeader = (PacketHeader*)pDataBuffer->GetBuffer();
	pHeader->CheckCode = 0x88;
	pHeader->dwUserData = dwUserData;
	pHeader->u64TargetID = u64TargetID;
	pHeader->dwSize = dwLen + sizeof(PacketHeader);
	pHeader->dwMsgID = dwMsgID;
	pHeader->dwPacketNo = 1;

	memcpy(pDataBuffer->GetBuffer() + sizeof(PacketHeader), pData, dwLen);

	pDataBuffer->SetTotalLenth(pHeader->dwSize);

	if (pConn->SendBuffer(pDataBuffer))
	{
		PostSendOperation(pConn);
		return TRUE;
	}

	return FALSE;
}


BOOL CNetManager::PostSendOperation(CConnection* pConnection)
{
	ERROR_RETURN_FALSE(pConnection != NULL);

	if (!pConnection->m_IsSending)
	{
		uv_async_init(m_pMainLoop, &pConnection->m_AsyncReq, On_Async_Event);

		uv_handle_set_data((uv_handle_t*)&pConnection->m_AsyncReq, (void*)pConnection);

		uv_async_send(&pConnection->m_AsyncReq);
	}

	return TRUE;
}