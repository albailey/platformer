#define DEV_MODE 1

#include "include/neslib.h"
#include "include/utils.h"


// ===== CONST DATA ==================
//palette for sprites
const unsigned char palSprites[16]={
	0x0f,0x17,0x27,0x37,
	0x0f,0x11,0x21,0x31,
	0x0f,0x15,0x25,0x35,
	0x0f,0x19,0x29,0x39
};

// VARS
static unsigned char lastPad, pad;

void processGame() {
  // game engine goes here
}

void main(void)
{
        // BG bank CHR0. sprite bank is CHR1
        bank_bg(0);
        bank_spr(1);
        ppu_on_all();
        // setup palette
	pal_spr(palSprites);
        pal_bg(palSprites);
	while(1)
	{
                // -- game loop --
		ppu_waitnmi();//wait for next TV frame

                // strobe joypad to get input
                // store last strobe and compare for changes
                lastPad = pad;
                pad = pad_poll(0);

                // game engine code
                processGame();

                // dev mode (show line on screen)
		showLine();
	}
}

