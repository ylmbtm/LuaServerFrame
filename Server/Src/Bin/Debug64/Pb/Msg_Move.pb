
„
Msg_Move.protoMsg_Game.proto"²
SkillCastReq

ObjectGuid (R
ObjectGuid
SkillID (RSkillID
HostX (RHostX
HostY (RHostY
HostZ (RHostZ
HostFt (RHostFt
TargetX (RTargetX
TargetY (RTargetY
TargetZ	 (RTargetZ
TargetFt
 (RTargetFt$
TargetObjects (RTargetObjects"(
SkillCastAck
RetCode (RRetCode"ë
SkillResultItem

ObjectGuid (R
ObjectGuid
SkillID (RSkillID
ActionID (RActionID
OrgX (ROrgX
OrgY (ROrgY
OrgZ (ROrgZ
OrgFt (ROrgFt
HpChange (RHpChange
bCrit	 (RbCrit">
SkillResultNtf,
ItemList (2.SkillResultItemRItemList"A
ObjectActionReq.

ActionList (2.ActionReqItemR
ActionList"A
ObjectActionNty.

ActionList (2.ActionNtyItemR
ActionList"¥
ActionReqItem

ObjectGuid (R
ObjectGuid
ActionID (RActionID
HostX (RHostX
HostY (RHostY
HostZ (RHostZ
HostFt (RHostFt"A
ObjectActionAck.

ActionList (2.ActionReqItemR
ActionList"Ã
ActionNtyItem

ObjectGuid (R
ObjectGuid
ActionID (RActionID
Camp (RCamp"
ObjectStatus (RObjectStatus
Speed (RSpeed
HostX (RHostX
HostY (RHostY
HostZ (RHostZ
HostFt	 (RHostFt
ActorID
 (RActorID
MountID (RMountID
Level (RLevel 
ControlerID (RControlerID
Hp (RHp
Mp (RMp
HpMax (RHpMax
MpMax (RMpMax
Equips (REquips"§
NewItem

ObjectGuid (R
ObjectGuid
ActionID (RActionID
ObjType (RObjType"
ObjectStatus (RObjectStatus
ActorID (RActorID
MountID (RMountID
Camp (RCamp
Name (	RName
Level	 (RLevel
Speed
 (RSpeed
HostGuid (RHostGuid 
ControlerID (RControlerID
SummonID (RSummonID
X (RX
Y (RY
Z (RZ
Ft (RFt
Hp (RHp
Mp (RMp
HpMax (RHpMax
MpMax (RMpMax
Equips (REquips"
Skills (2
.SkillItemRSkills"2
ObjectNewNty"
NewList (2.NewItemRNewList"1
ObjectRemoveNty

RemoveList (R
RemoveList"²

BulletItem

ObjectGuid (R
ObjectGuid

TargetGuid (R
TargetGuid

CasterGuid (R
CasterGuid
BulletID (RBulletID
X (RX
Y (RY
Z (RZ
Angle (RAngle
Speed	 (RSpeed
AccSpeed
 (RAccSpeed
LifeTime (RLifeTime
LeftTime (RLeftTime"7
BulletNewNtf'
ItemList (2.BulletItemRItemList",
HeartBeatReq
	TimeStamp (R	TimeStamp"L
HeartBeatAck
	TimeStamp (R	TimeStamp

ServerTime (R
ServerTime"1
ObjectDieNotify

ObjectGuid (R
ObjectGuid"4
Msg_RidingMountReq

ObjectGuid (R
ObjectGuid".
Msg_RidingMountAck
RetCode (RRetCode"S
Msg_RoleRebornReq

ObjectGuid (R
ObjectGuid

RebornType (R
RebornType"-
Msg_RoleRebornAck
RetCode (RRetCodebproto3