#ifndef _NET_MANAGER_H_
#define _NET_MANAGER_H_
#include "IBufferHandler.h"
#include "Connection.h"
////////////////////////////////////////////////
class CNetManager
{
	CNetManager(void);

	virtual ~CNetManager(void);
public:
	static CNetManager* GetInstancePtr()
	{
		static CNetManager NetManager;

		return &NetManager;
	}
public:
	BOOL	Start(UINT16 nPortNum,  UINT32 nMaxConn, IDataHandler* pBufferHandler, std::string& strListenIp);

	BOOL	Stop();

	BOOL    SendMessageData(UINT32 dwConnID,  UINT32 dwMsgID, UINT64 u64TargetID, UINT32 dwUserData,  const char* pData, UINT32 dwLen);

	BOOL    SendMessageBuff(UINT32 dwConnID, IDataBuffer* pBuffer);

	BOOL    SendMessageByUdp(UINT32 dwConnID, UINT32 dwMsgID, UINT64 u64TargetID, UINT32 dwUserData, const char* pData, UINT32 dwLen);

	CConnection*	ConnectTo_Sync(std::string strIpAddr, UINT16 sPort);

	CConnection*	ConnectTo_Async(std::string strIpAddr, UINT16 sPort);

	void HandleConnect(CConnection* pConnection, INT32 dwStatus);

	void HandleAccept(CConnection* pConnection, INT32 dwStatus);

	BOOL PostSendOperation(CConnection* pConnection);

	void RunLoop();

	uv_tcp_t						m_ListenSocket;
	uv_loop_t*						m_pMainLoop;
	uv_thread_t						m_LoopThreadID;
	IDataHandler*					m_pBufferHandler;

	//以下是udp
	uv_udp_t                        m_UdpSvrSocket;
	sockaddr                        m_udpClientAddr;
	IDataBuffer*                    m_pUdpRecvBuffer;
	uv_udp_send_t                   m_udpSendReq;
	uv_buf_t                        m_udpSendBuf;

	BOOL    StartUdp(INT32 nUdpPort);

	BOOL    StopUdp();

	static void OnUdpAllocBuff(uv_handle_t* pHandle, size_t suggested_size, uv_buf_t* buf);

	static void OnUdpReadData(uv_udp_t* handle, ssize_t nread, const uv_buf_t* buf, const struct sockaddr* addr, unsigned flags);

	static void OnUdpSend(uv_udp_send_t* pReq, int iStatus);



public:
};

#endif

