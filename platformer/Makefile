CC=cc65
CFLAGS=-Oi

GAME=platformer

objfiles= asm/crt0.o asm/utils.o $(GAME).o

all: clean build run

clean:
	rm -f $(objfiles)
	rm -f *.o
	rm -f asm/*.o
	rm -f $(GAME).s
	rm -f $(GAME).nes


build: $(GAME).c
	$(CC) $(CFLAGS) $(GAME).c --add-source
	ca65 asm/crt0.s
	ca65 asm/utils.s
	ca65 $(GAME).s
	ld65 -o $(GAME).nes -C nes.cfg $(objfiles) libs/runtime.lib

run:
	fceux $(GAME).nes
