#include "stdafx.h"
#include "LuaManager.h"
#include "GameService.h"
#include "PacketHeader.h"


CGameService::CGameService(void)
{

}

CGameService::~CGameService(void)
{

}


BOOL CGameService::OnNewConnect(UINT32 nConnID)
{
	lua_State* pLuaState = CLuaManager::GetInstancePtr()->GetLuaState();
	ERROR_RETURN_TRUE(pLuaState != NULL);
	int nStackTop = lua_gettop(pLuaState);

	lua_getglobal(pLuaState, "OnNewConnect");

	if (!lua_isfunction(pLuaState, -1))
	{
		lua_settop(pLuaState, nStackTop);
		return TRUE;
	}

	lua_pushinteger(pLuaState, nConnID);
	lua_pcall(pLuaState, 1, 1, 0);

	lua_settop(pLuaState, nStackTop);
	return TRUE;
}

BOOL CGameService::OnCloseConnect(UINT32 nConnID)
{
	lua_State* pLuaState = CLuaManager::GetInstancePtr()->GetLuaState();
	ERROR_RETURN_TRUE(pLuaState != NULL);
	int nStackTop = lua_gettop(pLuaState);

	lua_getglobal(pLuaState, "OnCloseConnect");

	if (!lua_isfunction(pLuaState, -1))
	{
		lua_settop(pLuaState, nStackTop);
		return TRUE;
	}

	lua_pushinteger(pLuaState, nConnID);
	lua_pcall(pLuaState, 1, 1, 0);

	lua_settop(pLuaState, nStackTop);
	return TRUE;
}

BOOL CGameService::OnSecondTimer()
{
	lua_State* pLuaState = CLuaManager::GetInstancePtr()->GetLuaState();
	ERROR_RETURN_TRUE(pLuaState != NULL);
	int nStackTop = lua_gettop(pLuaState);

	lua_getglobal(pLuaState, "OnSecondTimer");

	if (!lua_isfunction(pLuaState, -1))
	{
		lua_settop(pLuaState, nStackTop);
		return TRUE;
	}

	lua_pcall(pLuaState, 0, 1, 0);

	lua_settop(pLuaState, nStackTop);

	return TRUE;
}

BOOL CGameService::DispatchPacket(NetPacket* pNetPacket)
{
	PacketHeader* pHeader = (PacketHeader*)pNetPacket->m_pDataBuffer->GetBuffer();
	ERROR_RETURN_TRUE(pHeader != NULL);

	lua_State* pLuaState = CLuaManager::GetInstancePtr()->GetLuaState();
	ERROR_RETURN_TRUE(pLuaState != NULL);
	int nStackTop = lua_gettop(pLuaState);

	lua_getglobal(pLuaState, "Dispatch");

	if (!lua_isfunction(pLuaState, -1))
	{
		lua_settop(pLuaState, nStackTop);
		return TRUE;
	}

	lua_pushinteger(pLuaState, pNetPacket->m_dwMsgID);
	lua_pushinteger(pLuaState, pNetPacket->m_dwConnID);
	lua_pushlstring(pLuaState, pNetPacket->m_pDataBuffer->GetData(), pNetPacket->m_pDataBuffer->GetBodyLenth());

	lua_pcall(pLuaState, 3, 1, 0);

	lua_settop(pLuaState, nStackTop);
	return FALSE;
}

BOOL CGameService::SendMessage(UINT32 dwConnID, UINT32 dwMsgID, UINT64 u64TargetID, UINT32 dwUserData, const char* pdata, UINT32 dwLen)
{
	ERROR_RETURN_FALSE(dwConnID != 0);
	ERROR_RETURN_FALSE(ServiceBase::GetInstancePtr()->SendMsgRawData(dwConnID, dwMsgID, u64TargetID, dwUserData, pdata, dwLen));
	return TRUE;
}

UINT32 CGameService::ConnectTo(char* pStrIpAddr, UINT16 sPort)
{
	CConnection* pConnection = ServiceBase::GetInstancePtr()->ConnectTo(pStrIpAddr, sPort);
	if (pConnection == NULL)
	{
		return 0;
	}

	return pConnection->GetConnectionID();
}

VOID CGameService::LogError(char* lpszText)
{
	CLog::GetInstancePtr()->LogError(lpszText);

	return;
}

VOID CGameService::LogWarn(char* lpszText)
{
	CLog::GetInstancePtr()->LogWarnning(lpszText);

	return;
}

UINT64 CGameService::GetCurrentTimeTick()
{
	return CommonFunc::GetTickCount();
}

VOID CGameService::SetLogLevel(UINT32 nLevel)
{
	CLog::GetInstancePtr()->SetLogLevel(nLevel);
}
