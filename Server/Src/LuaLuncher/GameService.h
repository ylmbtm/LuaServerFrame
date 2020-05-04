#ifndef _GAME_SERVICE_H_
#define _GAME_SERVICE_H_
class CGameService : public IPacketDispatcher
{
public:
	CGameService(void);

	virtual ~CGameService(void);

	BOOL        OnNewConnect(UINT32 nConnID);

	BOOL        OnCloseConnect(UINT32 nConnID);

	BOOL        OnSecondTimer();

	BOOL        DispatchPacket(NetPacket* pNetPacket);

	BOOL        SendMessage(UINT32 dwConnID, UINT32 dwMsgID, UINT64 u64TargetID, UINT32 dwUserData, const char* pdata, UINT32 dwLen);

	UINT32      ConnectTo(char* pStrIpAddr, UINT16 sPort);

	VOID        LogError(char* lpszText);

	VOID        LogWarn(char* lpszText);

	UINT64      GetCurrentTimeTick();

	VOID        SetLogLevel(UINT32 nLevel);
};

#endif
