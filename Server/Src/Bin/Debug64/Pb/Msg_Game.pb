
ªF
Msg_Game.proto"S
	SkillItem
SkillID (RSkillID
Level (RLevel
KeyPos (RKeyPos"%
GmStopServerReq
Data (RData"+
GmStopServerAck
RetCode (RRetCode"O
CheckVersionReq"
ClientVerion (	RClientVerion
Channel (RChannel"O
CheckVersionAck
RetCode (RRetCode"
ClientVerion (	RClientVerion"‹
AccountRegReq 
AccountName (	RAccountName
Password (	RPassword
Channel (RChannel"
ClientVerion (	RClientVerion"G
AccountRegAck
RetCode (RRetCode
	AccountID (R	AccountID"¯
AccountLoginReq 
AccountName (	RAccountName
Password (	RPassword
Channel (RChannel"
ClientVerion (	RClientVerion 
FromChannel (RFromChannel"‰
AccountLoginAck
RetCode (RRetCode
	AccountID (R	AccountID
	LastSvrID (R	LastSvrID 
LastSvrName (	RLastSvrName"s
ClientServerListReq
	AccountID (R	AccountID
Channel (RChannel$
ClientVersion (	RClientVersion"š
ClientServerNode
SvrID (RSvrID
SvrName (	RSvrName
SvrState (RSvrState
SvrFlag (RSvrFlag 
SvrOpenTime (RSvrOpenTime"\
ClientServerListAck
RetCode (RRetCode+
SvrNode (2.ClientServerNodeRSvrNode"¤
SvrRegToSvrReq
ServerID (RServerID

ServerName (	R
ServerName
ServerIp (	RServerIp

ServerPort (R
ServerPort
HttpPort (RHttpPort"J
SvrRegToSvrAck
RetCode (RRetCode

NewSvrName (	R
NewSvrName"K
SelectServerReq
	AccountID (R	AccountID
ServerID (RServerID"Ã
SelectServerAck
RetCode (RRetCode
	AccountID (R	AccountID
ServerID (RServerID

ServerAddr (	R
ServerAddr

ServerPort (R
ServerPort
	LoginCode (R	LoginCode"d
RoleItem
RoleID (RRoleID
Name (	RName
Carrer (RCarrer
Level (RLevel"I
RoleListReq
	AccountID (R	AccountID
	LoginCode (R	LoginCode"l
RoleListAck
RetCode (RRetCode
	AccountID (R	AccountID%
RoleList (2	.RoleItemRRoleList"s
RoleCreateReq
	AccountID (R	AccountID
Name (	RName
Carrer (RCarrer
Channel (RChannel"‹
RoleCreateAck
RetCode (RRetCode
	AccountID (R	AccountID
RoleID (RRoleID
Name (	RName
Carrer (RCarrer"E
RoleDeleteReq
	AccountID (R	AccountID
RoleID (RRoleID")
RoleDeleteAck
RetCode (RRetCode"b
RoleLoginReq
	AccountID (R	AccountID
RoleID (RRoleID
	LoginCode (R	LoginCode"-
RoleLogoutReq
	AccountID (R	AccountID")
RoleLogoutAck
RetCode (RRetCode"g
RoleDisconnectReq
	AccountID (R	AccountID
RoleID (RRoleID
	LoginCode (R	LoginCode"-
RoleDisconnectAck
RetCode (RRetCode"*
RoleReconnectReq
RoleID (RRoleID",
RoleReconnectAck
RetCode (RRetCode"‡
CreateNewSceneReq
CopyID (RCopyID
CopyType (RCopyType
	PlayerNum (R	PlayerNum 
CreateParam (RCreateParam"Ù
CreateNewSceneAck
RetCode (RRetCode
CopyID (RCopyID
CopyGuid (RCopyGuid 
CreateParam (RCreateParam
ServerID (RServerID
CopyType (RCopyType
	PlayerNum (R	PlayerNum"w
EnterSceneReq
RoleID (RRoleID
ServerID (RServerID
CopyGuid (RCopyGuid
CopyID (RCopyID"É
EnterSceneAck
RetCode (RRetCode
CopyID (RCopyID
CopyGuid (RCopyGuid
RoleID (RRoleID
Carrer (RCarrer
ActorID (RActorID
RoleName (	RRoleName
Camp (RCamp
X	 (RX
Y
 (RY
Z (RZ
Ft (RFt
Hp (RHp
Mp (RMp
HpMax (RHpMax
MpMax (RMpMax
Speed (RSpeed
MountID (RMountID
Equips (REquips"
Skills (2
.SkillItemRSkills"%
BackToCityReq
Param (RParam")
BackToCityAck
RetCode (RRetCode"?
LeaveSceneReq
RoleID (RRoleID
Reason (RReason")
LeaveSceneAck
RetCode (RRetCode"?
AbortSceneReq
RoleID (RRoleID
Reason (RReason")
AbortSceneAck
RetCode (RRetCode"©
AbortSceneNty
RoleID (RRoleID
CopyID (RCopyID
CopyGuid (RCopyGuid
CopyType (RCopyType
ServerID (RServerID
Param (RParam"‘
TransRoleData
RoleID (RRoleID
Name (	RName
CarrerID (RCarrerID
ActorID (RActorID
Level (RLevel
MountID (RMountID
Robot (RRobot
Equips (REquips
	Propertys	 (R	Propertys"
Skills
 (2
.SkillItemRSkills"Ä
TransPetData
PetGuid (RPetGuid
PetID (RPetID
ActorID (RActorID
Name (	RName
Level (RLevel
	Propertys (R	Propertys"
Skills (2
.SkillItemRSkills"Ø
TransPartnerData 
PartnerGuid (RPartnerGuid
	PartnerID (R	PartnerID
ActorID (RActorID
Name (	RName
Level (RLevel
	Propertys (R	Propertys"
Skills (2
.SkillItemRSkills"°
TransferDataItem
Camp (RCamp*
RoleData (2.TransRoleDataRRoleData'
PetData (2.TransPetDataRPetData3
PartnerData (2.TransPartnerDataRPartnerData"D
TransferDataReq1

TransDatas (2.TransferDataItemR
TransDatas"“
TransferDataAck
RetCode (RRetCode
RoleID (RRoleID
CopyID (RCopyID
CopyGuid (RCopyGuid
ServerID (RServerID"y
NotifyIntoScene
RoleID (RRoleID
CopyID (RCopyID
CopyGuid (RCopyGuid
ServerID (RServerID"l
NearByRoleItem
RoleID (RRoleID
ActorID (RActorID
Level (RLevel
Name (	RName"y
CopyInsItem
CopyGuid (RCopyGuid
CopyID (RCopyID
CopyType (RCopyType
ServerID (RServerID"U
CopyReportReq
ServerID (RServerID(
CopyList (2.CopyInsItemRCopyList"
UseHpBottleReq"@
UseHpBottleAck
RetCode (RRetCode
Count (RCount"
UseMpBottleReq"@
UseMpBottleAck
RetCode (RRetCode
Count (RCount"Ž
ChatMessageReq
SrcName (	RSrcName
SrcID (RSrcID
Channel (RChannel
GuildID (RGuildID
Content (	RContent"*
ChatMessageAck
RetCode (RRetCode"Ž
ChatMessageNty
SrcName (	RSrcName
SrcID (RSrcID
Channel (RChannel
GuildID (RGuildID
Content (	RContent"š
SealAccountReq 
AccountName (	RAccountName
	AccountID (R	AccountID
Channel (RChannel
SealTime (RSealTime
Seal (RSeal"j
SealAccountAck
RetCode (RRetCode 
AccountName (	RAccountName
	AccountID (R	AccountID"L
SetLastServerNty
	AccountID (R	AccountID
ServerID (RServerID"#
	CommonReq
Param1 (RParam1"%
	CommonAck
RetCode (RRetCode"\
BroadMessageNotify
MsgID (RMsgID
ConnID (RConnID
MsgData (RMsgData"Æ
LogicRegToLoginReq
ServerID (RServerID

ServerName (	R
ServerName
ServerIp (	RServerIp

ServerPort (R
ServerPort
HttpPort (RHttpPort
	WatchPort (R	WatchPort"N
LogicRegToLoginAck
RetCode (RRetCode

NewSvrName (	R
NewSvrName"E
WatchHeartBeatReq
Data (RData
	ProcessID (R	ProcessID"_
WatchHeartBeatAck
RetCode (RRetCode
Data (RData
	ProcessID (R	ProcessID"G
SetupEquipReq
	EquipGuid (R	EquipGuid
BagGuid (RBagGuid")
SetupEquipAck
RetCode (RRetCode"-
UnsetEquipReq
	EquipGuid (R	EquipGuid")
UnsetEquipAck
RetCode (RRetCode"_
SetupGemReq
GemGuid (RGemGuid
BagGuid (RBagGuid
	TargetPos (R	TargetPos"'
SetupGemAck
RetCode (RRetCode"'
UnsetGemReq
GemGuid (RGemGuid"'
UnsetGemAck
RetCode (RRetCode"Q
SetupPartnerReq 
PartnerGuid (RPartnerGuid
	TargetPos (R	TargetPos"+
SetupPartnerAck
RetCode (RRetCode"/
UnsetPartnerReq
	TargetPos (R	TargetPos"+
UnsetPartnerAck
RetCode (RRetCode"K
SetupMountReq
	MountGuid (R	MountGuid
	TargetPos (R	TargetPos")
SetupMountAck
RetCode (RRetCode"-
UnsetMountReq
	MountGuid (R	MountGuid")
UnsetMountAck
RetCode (RRetCode"'
SetupPetReq
PetGuid (RPetGuid"'
SetupPetAck
RetCode (RRetCode"'
UnsetPetReq
PetGuid (RPetGuid"'
UnsetPetAck
RetCode (RRetCode"]
StoreBuyReq
	StoreType (R	StoreType
StoreID (RStoreID
BuyNum (RBuyNum"'
StoreBuyAck
RetCode (RRetCode"¤
ObjectChangeNotify
RoleID (RRoleID

ChangeType (R
ChangeType
	IntValue1 (R	IntValue1
	IntValue2 (R	IntValue2
StrValue (	RStrValue"ã
HitEffectItem
CastGuid (RCastGuid

TargetGuid (R
TargetGuid
	HurtValue (R	HurtValue
Crit (RCrit 
HitActionID (RHitActionID 
HitEffectID (RHitEffectID 
HitDistance (RHitDistance":
HitEffectNtf*
ItemList (2.HitEffectItemRItemList"

UseItemReq"

UseItemAck"'
MsgGetRandomNameReq
Sex (RSex")
MsgGetRandomNameAck
Name (	RNamebproto3