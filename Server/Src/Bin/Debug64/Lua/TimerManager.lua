-- 时间管理器
---@class TimerManager

TimerManager = {};

local this = TimerManager;

this.next_timer_id = 1;
this.isInit = false;


function TimerManager.Init()
	if this.isInit then
		return
	end
	this.isInit = true;

	this.timers = {};

end

function TimerManager.GetNextTimerId()
	this.next_timer_id = this.next_timer_id + 1;
	return this.next_timer_id;
end


function TimerManager.Update(timeTick)
	if table.nums(this.timers) == 0 then
		return
	end
	
	local removes = {};

	for i, v in pairs(this.timers) do
		if (v.loop > 0) and v.deadline <= timeTick then
			if v.callback then
				v.callback(i);
			end

			v.loop = v.loop - 1;
			v.deadline = timeTick + v.delayms;
		elseif v.loop <= 0 then
			table.insert(removes, i);
		end
	end

	for i, v in pairs(removes) do
		this.Cancel(v);
	end
end

function TimerManager.AddTimer(callback, millisecond, loop)
	if millisecond < 0 or callback == nil then
		G_GameServie:LogError("TimerManager.AddTimer param invalid")
		return -1;
	end
	
	loop = loop or 1;
	
	if loop < 0 then 
		loop = 9999999999;
	end 

	local timerId = this.GetNextTimerId();
	local deadline = G_GameServie:GetCurrentTimeTick() + millisecond;

	local t = {};
	t.delayms = millisecond;
	t.deadline = deadline;
	t.callback = callback;
	t.loop = loop;
	t.forever = false

	this.timers[timerId] = t;
	return timerId;
end

function TimerManager.Cancel(timerId)
	if timerId == nil then
		return
	end

	this.timers[timerId] = nil;
end

TimerManager.Init();
