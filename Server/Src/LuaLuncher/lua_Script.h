/*
** Lua binding: LuaScript
** Generated automatically by tolua++-1.0.93-lua53 on Mon May  4 14:08:39 2020.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_LuaScript_open (lua_State* tolua_S);

#include  "GameService.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_CGameService (lua_State* tolua_S)
{
 CGameService* self = (CGameService*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"CGameService");
}

/* method: new of class  CGameService */
#ifndef TOLUA_DISABLE_tolua_LuaScript_CGameService_new00
static int tolua_LuaScript_CGameService_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CGameService",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CGameService* tolua_ret = (CGameService*)  Mtolua_new((CGameService)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CGameService");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CGameService */
#ifndef TOLUA_DISABLE_tolua_LuaScript_CGameService_new00_local
static int tolua_LuaScript_CGameService_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CGameService",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CGameService* tolua_ret = (CGameService*)  Mtolua_new((CGameService)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CGameService");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  CGameService */
#ifndef TOLUA_DISABLE_tolua_LuaScript_CGameService_delete00
static int tolua_LuaScript_CGameService_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CGameService",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CGameService* self = (CGameService*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SendMessage of class  CGameService */
#ifndef TOLUA_DISABLE_tolua_LuaScript_CGameService_SendMessage00
static int tolua_LuaScript_CGameService_SendMessage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CGameService",0,&tolua_err) ||
     !tolua_isinteger(tolua_S,2,0,&tolua_err) ||
     !tolua_isinteger(tolua_S,3,0,&tolua_err) ||
     !tolua_isinteger(tolua_S,4,0,&tolua_err) ||
     !tolua_isinteger(tolua_S,5,0,&tolua_err) ||
     !tolua_isstring(tolua_S,6,0,&tolua_err) ||
     !tolua_isinteger(tolua_S,7,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CGameService* self = (CGameService*)  tolua_tousertype(tolua_S,1,0);
  unsigned int dwConnID = (( unsigned int)  tolua_tointeger(tolua_S,2,0));
  unsigned int dwMsgID = (( unsigned int)  tolua_tointeger(tolua_S,3,0));
  unsigned long long u64TargetID = (( unsigned long long)  tolua_tointeger(tolua_S,4,0));
  unsigned int dwUserData = (( unsigned int)  tolua_tointeger(tolua_S,5,0));
  const char* pdata = ((const char*)  tolua_tostring(tolua_S,6,0));
  unsigned int dwLen = (( unsigned int)  tolua_tointeger(tolua_S,7,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SendMessage'", NULL);
#endif
  {
    bool tolua_ret = (  bool)  self->SendMessage(dwConnID,dwMsgID,u64TargetID,dwUserData,pdata,dwLen);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SendMessage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ConnectTo of class  CGameService */
#ifndef TOLUA_DISABLE_tolua_LuaScript_CGameService_ConnectTo00
static int tolua_LuaScript_CGameService_ConnectTo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CGameService",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isinteger(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CGameService* self = (CGameService*)  tolua_tousertype(tolua_S,1,0);
  char* pStrIpAddr = ((char*)  tolua_tostring(tolua_S,2,0));
  unsigned short sPort = (( unsigned short)  tolua_tointeger(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ConnectTo'", NULL);
#endif
  {
   unsigned int tolua_ret = ( unsigned int)  self->ConnectTo(pStrIpAddr,sPort);
   tolua_pushinteger(tolua_S,(lua_Integer)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ConnectTo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LogError of class  CGameService */
#ifndef TOLUA_DISABLE_tolua_LuaScript_CGameService_LogError00
static int tolua_LuaScript_CGameService_LogError00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CGameService",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CGameService* self = (CGameService*)  tolua_tousertype(tolua_S,1,0);
  char* lpszText = ((char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LogError'", NULL);
#endif
  {
   self->LogError(lpszText);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LogError'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LogWarn of class  CGameService */
#ifndef TOLUA_DISABLE_tolua_LuaScript_CGameService_LogWarn00
static int tolua_LuaScript_CGameService_LogWarn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CGameService",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CGameService* self = (CGameService*)  tolua_tousertype(tolua_S,1,0);
  char* lpszText = ((char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LogWarn'", NULL);
#endif
  {
   self->LogWarn(lpszText);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LogWarn'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCurrentTimeTick of class  CGameService */
#ifndef TOLUA_DISABLE_tolua_LuaScript_CGameService_GetCurrentTimeTick00
static int tolua_LuaScript_CGameService_GetCurrentTimeTick00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CGameService",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CGameService* self = (CGameService*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCurrentTimeTick'", NULL);
#endif
  {
   unsigned long long tolua_ret = ( unsigned long long)  self->GetCurrentTimeTick();
   tolua_pushinteger(tolua_S,(lua_Integer)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCurrentTimeTick'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetLogLevel of class  CGameService */
#ifndef TOLUA_DISABLE_tolua_LuaScript_CGameService_SetLogLevel00
static int tolua_LuaScript_CGameService_SetLogLevel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CGameService",0,&tolua_err) ||
     !tolua_isinteger(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CGameService* self = (CGameService*)  tolua_tousertype(tolua_S,1,0);
  unsigned int nLevel = (( unsigned int)  tolua_tointeger(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetLogLevel'", NULL);
#endif
  {
   self->SetLogLevel(nLevel);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetLogLevel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_LuaScript_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CGameService","CGameService","",tolua_collect_CGameService);
  #else
  tolua_cclass(tolua_S,"CGameService","CGameService","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CGameService");
   tolua_function(tolua_S,"new",tolua_LuaScript_CGameService_new00);
   tolua_function(tolua_S,"new_local",tolua_LuaScript_CGameService_new00_local);
   tolua_function(tolua_S,".call",tolua_LuaScript_CGameService_new00_local);
   tolua_function(tolua_S,"delete",tolua_LuaScript_CGameService_delete00);
   tolua_function(tolua_S,"SendMessage",tolua_LuaScript_CGameService_SendMessage00);
   tolua_function(tolua_S,"ConnectTo",tolua_LuaScript_CGameService_ConnectTo00);
   tolua_function(tolua_S,"LogError",tolua_LuaScript_CGameService_LogError00);
   tolua_function(tolua_S,"LogWarn",tolua_LuaScript_CGameService_LogWarn00);
   tolua_function(tolua_S,"GetCurrentTimeTick",tolua_LuaScript_CGameService_GetCurrentTimeTick00);
   tolua_function(tolua_S,"SetLogLevel",tolua_LuaScript_CGameService_SetLogLevel00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_LuaScript (lua_State* tolua_S) {
 return tolua_LuaScript_open(tolua_S);
};
#endif

