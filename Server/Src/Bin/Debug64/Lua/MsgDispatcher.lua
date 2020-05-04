-- 网络消息分发
---@class MsgDispatcher

MsgDispatcher = {};

local this = MsgDispatcher;
this.isInit = false;
function MsgDispatcher.Init()
	if this.isInit then
		return
	end
	this.isInit = true;

	this.handlermap = {};

end

function Dispatch(msgid, connid, msgdata) 
	local handler = this.handlermap[msgid];
	if handler == nil then 
		return ;
	end;
		
	handler(msgid, connid, msgdata);
end

function MsgDispatcher.RegisterMsgHandler(msgid, handler)
	this.handlermap[msgid] = handler;
end

function MsgDispatcher.Cancel(msgid)
	if msgid == nil then
		return
	end

	this.handlermap[msgid] = nil;
end

MsgDispatcher.Init();
