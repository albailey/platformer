
#include "include/neslib.h"
#include "include/settings.h"
#include "include/utils.h"

#include "include/movement.h"

#include "include/player1.h"
// TO DO: add support for player2

#include "include/graphics.h"


// PLAYER related controls and display
// updatePlayer
//  - takes a current sprite index
//  - adds sprites to the update
//  - and returns the new index
// TO DO:  add support for direction
// TO DO: add support for animation sequences
// TO DO: add support for different player states
unsigned char updatePlayer(unsigned char in_spr) {
   unsigned char spr = in_spr;
   spr=oam_spr(POS(player_x),
               POS(player_y),
               PLAYER_SPRITE,
               PLAYER_ATTRIB,
               spr);
   return spr;
}

void handleInput(){
  // apply friction to previous velocity
  // apply acceleration to current velocity
  // clamp velocity between 0 and max speed
if (pad & PAD_LEFT) {
  // if previously moving right, subtract FRICTION (clamp value 0)
  if (velocity_x > 0) {
    velocity_x -= FRICTION;
    if (velocity_x < 0){
        velocity_x = 0;
    }
  }
  velocity_x -= ACCELERATION;
  if (velocity_x < MIN_VELOCITY) {
     velocity_x = MIN_VELOCITY;
  }
} else if (pad & PAD_RIGHT) {
  // if previously moving left, add FRICTION (clamp value 0)
  if (velocity_x < 0) {
    velocity_x += FRICTION;
    if (velocity_x > 0) {
      velocity_x = 0;
    }
  }
  velocity_x += ACCELERATION;
  if (velocity_x > MAX_VELOCITY) {
     velocity_x = MAX_VELOCITY;
  }
} else { 
  // neither left or right.
  if (velocity_x > FRICTION) {
     velocity_x -= FRICTION;
  } else if(velocity_x < -FRICTION) {
     velocity_x += FRICTION;
  } else {
    velocity_x = 0;
  }
}

if (pad & PAD_UP) {
  velocity_y = -ACCELERATION;
} else if (pad & PAD_DOWN) {
  velocity_y = ACCELERATION;
} else {
 velocity_y = 0;
}
  player_x += velocity_x;
  player_y += velocity_y;
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

        // place player in middle of the screen
        player_x = 160 << 4;
        player_y = 120 << 4;
        // not moving
        velocity_x = 0;
        velocity_y = 0;

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


