-- Olimex STM32-E407 board configuration

return {
  cpu = 'stm32f407zg',
  components = {
    sercon = { uart = 2, speed = 115200 },
    romfs = true,
    advanced_shell = true,
    term = { lines = 25, cols = 80 },
    linenoise = { shell_lines = 10, lua_lines = 50 },
    rpc = { uart = 2, speed = 115200 },
    adc = { buf_size = 2 },
    xmodem = true,
    cints = true, 
    luaints = true
  },
  config = {
    egc = { mode = "alloc" },
    vtmr = { num = 4, freq = 10 },
    ram = { internal_rams = 2 },
    clocks = { external = 12000000, cpu = 168000000 }
  },
  modules = {
    generic = { 'all', "-i2c", "-net" },
    platform = 'all',
  },
}

