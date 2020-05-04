
local _, LuaDebuggee = pcall(require, 'LuaDebuggee')
if LuaDebuggee and LuaDebuggee.StartDebug then
	LuaDebuggee.StartDebug('127.0.0.1', 9826)
else
	print('Please read the FAQ.pdf')
end

local protobuf = require "protobuf"

require "TimerManager"
require "MsgDispatcher"
require "table_utility"

protobuf.register_file("./pb/Msg_Game.pb")

G_GameServie = CGameService:new();
--主入口
function Main() 
	
	G_GameServie:SetLogLevel(4);
	
	TimerManager.AddTimer(TimerCallback, 3000, 100);
	
	return true
end


--测试定时器
function TimerCallback() 
	G_GameServie:LogError("Test Timer ");
end

--返回监听ip地址和端口号
function ServerListen()
	return "127.0.0.1", 9001;
end

--服务器每帧调用
function Update(timetick)  
	--G_GameServie:LogError(timetick);
	TimerManager.Update(timetick);
end

--网络消息
function Dispatch(msgid, connid, msgdata) 
	G_GameServie:LogError(msgid);
	MsgDispatcher.Dispatch(msgid, connid, msgdata);
	
end

--收到新的连接通知
function OnNewConnect(connid) 
	G_GameServie:LogError("OnNewConnect");
end

--收到连接断开通知
function OnCloseConnect(connid) 
	G_GameServie:LogError("OnCloseConnect");
end

--秒计时器(每秒会调用一次)
function OnSecondTimer()		
	G_GameServie:LogError("OnSecondTimer");
end
