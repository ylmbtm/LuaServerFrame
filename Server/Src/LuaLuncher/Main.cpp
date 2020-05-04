// LogicServer.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "CrashReport.h"
#include "CommandLine.h"
#include "LuaManager.h"
#include "Lua_Script.h"
#include "GameService.h"

//消息需经通知lua
//update需要通知lua

//给lua的方法
//1.发送网络消息


int main(int argc, char* argv[])
{
	SetCrashReport("LuaLuncher");

	CCommandLine cmdLine(argc, argv);

	CommonFunc::SetCurrentWorkDir("");

	if (!CLog::GetInstancePtr()->Start(cmdLine.GetStrValue("AppName"), "log"))
	{
		return FALSE;
	}

	if (!CLuaManager::GetInstancePtr()->Init())
	{
		CLog::GetInstancePtr()->LogError("初始化Lua环境失败!");
		return FALSE;
	}

	if (!luaopen_LuaScript(CLuaManager::GetInstancePtr()->GetLuaState()))
	{
		CLog::GetInstancePtr()->LogError("导出Lua接口失败!");
		return FALSE;
	}

	if (!CLuaManager::GetInstancePtr()->LoadScriptFile(".\\Lua\\main.lua"))
	{
		CLog::GetInstancePtr()->LogError("加载lua代码失败!");
		return FALSE;
	}

	CHAR szListenIp[128] = { 0 };
	UINT32 nPort = 0;
	if (!CLuaManager::GetInstancePtr()->CallLuaFunction("ServerListen", "=si", &szListenIp, &nPort))
	{
		CLog::GetInstancePtr()->LogError("执行lua ServerListen函数失败!");
		return FALSE;
	}

	CGameService _tGameService;

	if (!ServiceBase::GetInstancePtr()->StartNetwork(nPort, 10000, &_tGameService, szListenIp))
	{
		CLog::GetInstancePtr()->LogError("启动服务失败!");
		return FALSE;
	}

	CLog::GetInstancePtr()->LogError("程序开始!");

	bool bResult = true;
	CLuaManager::GetInstancePtr()->CallLuaFunction("Main", "=b", &bResult);
	if (!bResult)
	{
		CLog::GetInstancePtr()->LogError("执行lua Main函数失败!");
		return FALSE;
	}

	while (bResult)
	{
		ServiceBase::GetInstancePtr()->Update();

		//调用lua的更新方法
		CLuaManager::GetInstancePtr()->CallLuaFunction("Update", "l=", CommonFunc::GetTickCount());

		CommonFunc::Sleep(1);
	}

	UnSetCrashReport();

	return 0;
}

