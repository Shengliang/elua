#scons board=MBED cpu=LPC1768 toolchain=codesourcery $1 $2 $3 $4 $5 $6 $7 $8 $9
#http://wiki.eluaproject.net/Compiling_eLua_en_Gabriel
#http://wiki.eluaproject.net/mbedLPC1768
lua build_elua.lua board=mbed
arm-none-eabi-objcopy -O binary elua_lua_mbed.elf elua.bin
