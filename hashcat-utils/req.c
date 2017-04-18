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

#define LOWER 0x1
#define UPPER 0x2
#define DIGIT 0x4
#define OTHER 0x8

/**
 * name...: req.c
 * author.: atom
 */

int main (int argc, char *argv[])
{
  if (argc != 2)
  {
    fprintf (stderr, "usage: %s req_mask < infile > outfile\n", argv[0]);

    return (-1);
  }

  #ifdef _WIN
  setmode (0, O_BINARY);
  #endif

  int req_mask = atoi (argv[1]);

  char line_buf[BUFSIZ];

  int line_len;

  while ((line_len = fgetl (stdin, BUFSIZ, line_buf)) != -1)
  {
    if (line_len == 0) continue;

    int cur_mask = 0;

    int p;

    for (p = 0; p < line_len; p++)
    {
           if ((line_buf[p] >=  'a') && (line_buf[p] <=  'z')) cur_mask |= LOWER;
      else if ((line_buf[p] >=  'A') && (line_buf[p] <=  'Z')) cur_mask |= UPPER;
      else if ((line_buf[p] >=  '0') && (line_buf[p] <=  '9')) cur_mask |= DIGIT;
      else if ((line_buf[p] >= 0x20) && (line_buf[p] <= 0x7e)) cur_mask |= OTHER;
    }

    if ((cur_mask & req_mask) != req_mask) continue;

    puts (line_buf);
  }

  return 0;
}
