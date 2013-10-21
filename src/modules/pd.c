// Module for interfacing with platform data

//#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include "platform.h"
#include "auxmods.h"
#include "lrotable.h"

#define MACRO_NAME( x ) MACRO_AGAIN( x )
#define MACRO_AGAIN( x ) #x

// Lua: platform = platform()
static int pd_platform( lua_State* L )
{
  lua_pushstring( L, MACRO_NAME( ELUA_PLATFORM ) );
  return 1;
}

// Lua: cpuname = cpu()
static int pd_cpu( lua_State* L )
{
  lua_pushstring( L, MACRO_NAME( ELUA_CPU ) ); 
  return 1;
}

// Lua: boardname = board()
static int pd_board( lua_State* L )
{
  lua_pushstring( L, MACRO_NAME( ELUA_BOARD ) );
  return 1;
}

u8 platform_rd_u8(u32 addr)
{
  u8* mem = (u8*)addr;
  return *mem;
}

u32 platform_rd_u32(u32 addr)
{
  u32* mem = (u32*)addr;
  return *mem;
}

// Lua: output = md(addr, len)
static int pd_md( lua_State* L )
{
  u32 i;
  u32 addr = ( u32 )luaL_checkinteger( L, 1 );
  u32 len  = ( u32 )luaL_checkinteger( L, 2 );
  luaL_Buffer b;
  int data;
  //printf("\n0x%08X 0x%X", addr, len);
  luaL_buffinit( L, &b );
  for( i = 0; i < len; i ++ )
  {
      data = platform_rd_u8(addr+i);
      //printf("\n%02X ", data);
      luaL_addchar( &b, ( u8 )data );
  }
  luaL_pushresult( &b );
  return 1;
}

// Module function map
#define MIN_OPT_LEVEL 2
#include "lrodefs.h"
const LUA_REG_TYPE pd_map[] = 
{
  { LSTRKEY( "platform" ), LFUNCVAL( pd_platform ) }, 
  { LSTRKEY( "cpu" ), LFUNCVAL( pd_cpu ) },
  { LSTRKEY( "board" ), LFUNCVAL( pd_board ) },
  { LSTRKEY( "md" ), LFUNCVAL( pd_md ) },
  { LNILKEY, LNILVAL }
};

LUALIB_API int luaopen_pd( lua_State* L )
{
  LREGISTER( L, AUXLIB_PD, pd_map );
}
