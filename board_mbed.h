// Lua board configuration file, automatically generated

#ifndef __GENERATED_MBED_H__
#define __GENERATED_MBED_H__

////////////////////////////////////////////////////////////////////////////////
// Configuration for section 'components'

// Configuration for element 'romfs'
#define BUILD_ROMFS

// Configuration for element 'adc'
#define ADC_BUF_SIZE                     2
#define BUILD_ADC

// Configuration for element 'linenoise'
#define LINENOISE_HISTORY_SIZE_LUA       50
#define LINENOISE_HISTORY_SIZE_SHELL     10
#define BUILD_LINENOISE

// Configuration for element 'sercon'
#define CON_FLOW_TYPE                    PLATFORM_UART_FLOW_NONE
#define CON_UART_SPEED                   115200
#define CON_TIMER_ID                     PLATFORM_TIMER_SYS_ID
#define CON_UART_ID                      0
#define BUILD_CON_GENERIC

// Configuration for element 'xmodem'
#define BUILD_XMODEM

// Configuration for element 'rpc'
#define RPC_UART_SPEED                   115200
#define RPC_TIMER_ID                     PLATFORM_TIMER_SYS_ID
#define RPC_UART_ID                      0
#define BUILD_RPC

// Configuration for element 'term'
#define TERM_LINES                       25
#define TERM_COLS                        80
#define BUILD_TERM

// Configuration for element 'shell'
#define BUILD_SHELL

// Configuration for element 'lpc17xx_semifs'
#define BUILD_SEMIFS

////////////////////////////////////////////////////////////////////////////////
// Configuration for section 'config'

// Configuration for element 'egc'
#define EGC_INITIAL_MODE                 ( EGC_ON_ALLOC_FAILURE )

// Configuration for element 'ram'
#define MEM_START_ADDRESS                { ( u32 )( INTERNAL_RAM1_FIRST_FREE ),( u32 )( INTERNAL_RAM2_FIRST_FREE ) }
#define MEM_END_ADDRESS                  { ( u32 )( INTERNAL_RAM1_LAST_FREE ),( u32 )( INTERNAL_RAM2_LAST_FREE ) }

// Configuration for element 'vtmr'
#define VTMR_FREQ_HZ                     1
#define VTMR_NUM_TIMERS                  0

///////////////////////////////////////////////////////////////////////////////
// Static sanity checks and additional defines

#if defined( ELUA_BOOT_RPC ) && !defined( BUILD_RPC )
#define BUILD_RPC
#endif

#if defined( BUILD_LUA_INT_HANDLERS ) || defined( BUILD_C_INT_HANDLERS )
  #define BUILD_INT_HANDLERS

  #ifndef INT_TMR_MATCH
  #define INT_TMR_MATCH         ELUA_INT_INVALID_INTERRUPT
  #endif
#endif // #if defined( BUILD_LUA_INT_HANDLERS ) || defined( BUILD_C_INT_HANDLERS )

#ifndef VTMR_NUM_TIMERS
#define VTMR_NUM_TIMERS       0
#endif // #ifndef VTMR_NUM_TIMERS

#ifndef SERMUX_FLOW_TYPE
#define SERMUX_FLOW_TYPE      PLATFORM_UART_FLOW_NONE
#endif

#ifndef CON_FLOW_TYPE
#define CON_FLOW_TYPE         PLATFORM_UART_FLOW_NONE
#endif

#ifndef CON_TIMER_ID
#define CON_TIMER_ID          PLATFORM_TIMER_SYS_ID
#endif

#ifndef RFS_FLOW_TYPE
#define RFS_FLOW_TYPE         PLATFORM_UART_FLOW_NONE
#endif

#ifdef ELUA_BOOT_RPC
  #ifndef RPC_UART_ID
    #define RPC_UART_ID       CON_UART_ID
  #endif

  #ifndef RPC_TIMER_ID
    #define RPC_TIMER_ID      PLATFORM_TIMER_SYS_ID
  #endif

  #ifndef RPC_UART_SPEED
    #define RPC_UART_SPEED    CON_UART_SPEED
  #endif
#endif // #ifdef ELUA_BOOT_RPC

#if ( defined( BUILD_RFS ) || defined( BUILD_SERMUX ) || defined( CON_BUF_SIZE ) || defined ( CDC_BUF_SIZE ) ) && !defined( BUF_ENABLE_UART )
#define BUF_ENABLE_UART
#endif

#if defined( ADC_BUF_SIZE ) && !defined( BUF_ENABLE_ADC )
#define BUF_ENABLE_ADC
#endif

#ifndef CPU_FREQUENCY
#define CPU_FREQUENCY         0
#endif

////////////////////////////////////////////////////////////////////////////////
// Module configuration

#define PLATFORM_MODULES_LINE            _ROM( "mbed", luaopen_platform, platform_map )
#define PS_LIB_TABLE_NAME                "mbed"
#define PLATFORM_MODULES_ENABLE

#if defined( BUILD_ADC ) && ( NUM_ADC > 0 )
#define MODULE_ADC_LINE                  _ROM( AUXLIB_ADC, luaopen_adc, adc_map )
#else
#define MODULE_ADC_LINE
#warning Unable to include generic module 'adc' in the image
#endif

#define MODULE_LUA_STRING_LINE           _ROM( LUA_STRLIBNAME, luaopen_string, strlib )
#define MODULE_BIT_LINE                  _ROM( AUXLIB_BIT, luaopen_bit, bit_map )

#if ( NUM_TIMER > 0 )
#define MODULE_TMR_LINE                  _ROM( AUXLIB_TMR, luaopen_tmr, tmr_map )
#else
#define MODULE_TMR_LINE
#warning Unable to include generic module 'tmr' in the image
#endif

#if defined( BUILD_RPC )
#define MODULE_RPC_LINE                  _ROM( AUXLIB_RPC, luaopen_rpc, rpc_map )
#else
#define MODULE_RPC_LINE
#warning Unable to include generic module 'rpc' in the image
#endif

#if defined( BUILD_TERM )
#define MODULE_TERM_LINE                 _ROM( AUXLIB_TERM, luaopen_term, term_map )
#else
#define MODULE_TERM_LINE
#warning Unable to include generic module 'term' in the image
#endif

#define MODULE_LUA_CO_LINE               _ROM( LUA_COLIBNAME, luaopen_dummy, co_funcs )
#define MODULE_ELUA_LINE                 _ROM( AUXLIB_ELUA, luaopen_elua, elua_map )
#define MODULE_PACK_LINE                 _ROM( AUXLIB_PACK, luaopen_pack, pack_map )

#if ( NUM_UART > 0 )
#define MODULE_UART_LINE                 _ROM( AUXLIB_UART, luaopen_uart, uart_map )
#else
#define MODULE_UART_LINE
#warning Unable to include generic module 'uart' in the image
#endif

#if ( NUM_CAN > 0 )
#define MODULE_CAN_LINE                  _ROM( AUXLIB_CAN, luaopen_can, can_map )
#else
#define MODULE_CAN_LINE
#warning Unable to include generic module 'can' in the image
#endif

#define MODULE_LUA_TABLE_LINE            _ROM( LUA_TABLIBNAME, luaopen_table, tab_funcs )
#define MODULE_LUA_DEBUG_LINE            _ROM( LUA_DBLIBNAME, luaopen_debug, dblib )
#define MODULE_LUA_MATH_LINE             _ROM( LUA_MATHLIBNAME, luaopen_math, math_map )
#define MODULE_CPU_LINE                  _ROM( AUXLIB_CPU, luaopen_cpu, cpu_map )

#if ( NUM_PWM > 0 )
#define MODULE_PWM_LINE                  _ROM( AUXLIB_PWM, luaopen_pwm, pwm_map )
#else
#define MODULE_PWM_LINE
#warning Unable to include generic module 'pwm' in the image
#endif

#if ( NUM_PIO > 0 )
#define MODULE_PIO_LINE                  _ROM( AUXLIB_PIO, luaopen_pio, pio_map )
#else
#define MODULE_PIO_LINE
#warning Unable to include generic module 'pio' in the image
#endif

#define MODULE_PD_LINE                   _ROM( AUXLIB_PD, luaopen_pd, pd_map )

#define LUA_PLATFORM_LIBS_ROM\
  PLATFORM_MODULES_LINE\
  MODULE_ADC_LINE\
  MODULE_LUA_STRING_LINE\
  MODULE_BIT_LINE\
  MODULE_TMR_LINE\
  MODULE_RPC_LINE\
  MODULE_TERM_LINE\
  MODULE_LUA_CO_LINE\
  MODULE_ELUA_LINE\
  MODULE_PACK_LINE\
  MODULE_UART_LINE\
  MODULE_CAN_LINE\
  MODULE_LUA_TABLE_LINE\
  MODULE_LUA_DEBUG_LINE\
  MODULE_LUA_MATH_LINE\
  MODULE_CPU_LINE\
  MODULE_PWM_LINE\
  MODULE_PIO_LINE\
  MODULE_PD_LINE

#define PL_MODULE_PIO_LINE               _ROM( AUXLIB_PIO, luaopen_mbed_pio, mbed_pio_map )

#define PLATFORM_MODULES_LIBS_ROM\
  PL_MODULE_PIO_LINE

#define LUA_LIBS_NOLTR\
  { LUA_IOLIBNAME, luaopen_io },\
  { LUA_LOADLIBNAME, luaopen_package },\

#endif // #ifndef __GENERATED_MBED_H__
