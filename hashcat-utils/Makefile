##
##  Makefile
##

CFLAGS = -Wall -W -pipe -g -O2 -ansi

all: clean release

release: posix windows
	$(STRIP_POSIX)   --strip-unneeded -R .comment *.bin
	$(STRIP_WINDOWS) --strip-unneeded -R .comment *.exe
	chmod 600 Makefile *.c *.exe
	chmod 700 *.bin

clean:
	rm -f core *.bin *.exe

##
## POSIX
##

CC_POSIX       = gcc
STRIP_POSIX    = strip
CFLAGS_POSIX   = $(CFLAGS)

posix:
	${CC_POSIX} ${CFLAGS_POSIX} -o combinator.bin combinator.c
	${CC_POSIX} ${CFLAGS_POSIX} -o cutb.bin cutb.c
	${CC_POSIX} ${CFLAGS_POSIX} -o expander.bin expander.c
	${CC_POSIX} ${CFLAGS_POSIX} -o gate.bin gate.c
	${CC_POSIX} ${CFLAGS_POSIX} -o hcstatgen.bin hcstatgen.c
	${CC_POSIX} ${CFLAGS_POSIX} -o len.bin len.c
	${CC_POSIX} ${CFLAGS_POSIX} -o morph.bin morph.c
	${CC_POSIX} ${CFLAGS_POSIX} -o permute.bin permute.c
	${CC_POSIX} ${CFLAGS_POSIX} -o prepare.bin prepare.c
	${CC_POSIX} ${CFLAGS_POSIX} -o req.bin req.c
	${CC_POSIX} ${CFLAGS_POSIX} -o rli.bin rli.c
	${CC_POSIX} ${CFLAGS_POSIX} -o rli2.bin rli2.c
	${CC_POSIX} ${CFLAGS_POSIX} -o splitlen.bin splitlen.c

##
## WINDOWS
##

CC_WINDOWS     = /usr/bin/x86_64-w64-mingw32-gcc
STRIP_WINDOWS  = /usr/bin/x86_64-w64-mingw32-strip
CFLAGS_WINDOWS = $(CFLAGS) -D_WIN
GLOB_WINDOWS   = /usr/x86_64-w64-mingw32/lib/CRT_glob.o

windows:
	${CC_WINDOWS} ${CFLAGS_WINDOWS} -o combinator.exe combinator.c
	${CC_WINDOWS} ${CFLAGS_WINDOWS} -o cutb.exe cutb.c
	${CC_WINDOWS} ${CFLAGS_WINDOWS} -o expander.exe expander.c
	${CC_WINDOWS} ${CFLAGS_WINDOWS} -o gate.exe gate.c
	${CC_WINDOWS} ${CFLAGS_WINDOWS} -o hcstatgen.exe hcstatgen.c
	${CC_WINDOWS} ${CFLAGS_WINDOWS} -o len.exe len.c
	${CC_WINDOWS} ${CFLAGS_WINDOWS} -o morph.exe morph.c
	${CC_WINDOWS} ${CFLAGS_WINDOWS} -o permute.exe permute.c
	${CC_WINDOWS} ${CFLAGS_WINDOWS} -o prepare.exe prepare.c
	${CC_WINDOWS} ${CFLAGS_WINDOWS} -o req.exe req.c
	${CC_WINDOWS} ${CFLAGS_WINDOWS} -o rli.exe rli.c ${GLOB_WINDOWS}
	${CC_WINDOWS} ${CFLAGS_WINDOWS} -o rli2.exe rli2.c
	${CC_WINDOWS} ${CFLAGS_WINDOWS} -o splitlen.exe splitlen.c
