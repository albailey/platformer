
#include "include/neslib.h"
#include "include/settings.h"
#include "include/utils.h"


// ===== CONST DATA ==================
//palette for sprites
// TO DO: move this to a settings or example file
const unsigned char palSprites[16]={
	0x0f,0x17,0x27,0x37,
	0x0f,0x11,0x21,0x31,
	0x0f,0x15,0x25,0x35,
	0x0f,0x19,0x29,0x39
};

// VARS
static unsigned char lastPad, pad;
// TO DO: add support for fractional movement of player
static unsigned char player_x, player_y;

// PLAYER related controls and display
// updatePlayer takes a current sprite index, adds sprites to the update, and returns the new index
// TO DO:  add support for direction
// TO DO: add support for animation sequences
// TO DO: add support for different player states
unsigned char updatePlayer(unsigned char in_spr) {
   unsigned char spr = in_spr;
   spr=oam_spr(player_x  , player_y,   PLAYER_SPRITE, PLAYER_ATTRIB, spr);
   return spr;
}

void handleInput(){
if (pad & PAD_LEFT) {
  player_x -= PLAYER_SPEED;
}
if (pad & PAD_RIGHT) {
  player_x += PLAYER_SPEED;
}
if (pad & PAD_UP) {
  player_y -= PLAYER_SPEED;
}
if (pad & PAD_DOWN) {
  player_y += PLAYER_SPEED;
}

}

// This is a minimal game engine that does hardly anything (yet)
// TO DO: add support for multiple players
void processGame() {
  // game engine goes here
  unsigned char spr = 0;
  handleInput();
  // display player
  spr = updatePlayer(spr);
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

        // NEED:  level loading, game states, etc..
        // FOR NOW:  using a sample level
        player_x = 100;
        player_y = 100;
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

