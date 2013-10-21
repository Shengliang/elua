// Shell: 'cat' implementation

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "shell.h"
#include "common.h"
#include "type.h"
#include "platform_conf.h"

const char shell_help_mem[] = "<addr> <len>"
  "  <addr>: 32-bit address (in hex format xxxxxxxx).\n"
  "  <len> : 16-bit length (in hex format xxxx)\n";
const char shell_help_summary_mem[] = "memory dump";

void mem_dump(unsigned int addr, unsigned int len)
{
  unsigned int* mem;
  int i;
  mem = (unsigned int*) addr;
  for(i=0; i<len; i++) {
    if(0==(i%4))printf("\n");
     printf("%08X ", mem[i]);
  }
  printf("\n");
}

void shell_mem( int argc, char **argv )
{
  unsigned int addr, len;
  unsigned i;

  for( i = 1; i < argc; i ++ )
  {
      printf("%d:%s\n", i, argv[i]);
  }

  if( argc < 3 )
  {
    shellh_show_help( argv[ 0 ], shell_help_mem );
    return;
  }

  sscanf(argv[1], "%X", &addr);
  sscanf(argv[2], "%X", &len);
  printf("\n%s %X %X", argv[0], addr, len);
  mem_dump(addr, len);
  return;
}
