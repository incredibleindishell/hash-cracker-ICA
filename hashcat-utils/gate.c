#define _GNU_SOURCE
#define _FILE_OFFSET_BITS 64
#define __MSVCRT_VERSION__ 0x0700

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include "utils.c"

/**
 * name...: gate.c
 * author.: atom
 */

int main (int argc, char *argv[])
{
  if (argc != 3)
  {
    fprintf (stderr, "usage: %s mod offset < infile > outfile\n", argv[0]);

    return (-1);
  }

  #ifdef _WIN
  setmode (0, O_BINARY);
  #endif

  int mod = atoi (argv[1]);

  int offset = atoi (argv[2]);

  if (offset >= mod)
  {
    fprintf (stderr, "offset >= mod\n");

    return (-1);
  }

  int pos = 0;

  char line_buf[BUFSIZ];

  int line_len;

  while ((line_len = fgetl (stdin, BUFSIZ, line_buf)) != -1)
  {
    if (line_len == 0) continue;

    if (pos == mod) pos = 0;

    if ((pos++ % mod) != offset) continue;

    puts (line_buf);
  }

  return 0;
}
