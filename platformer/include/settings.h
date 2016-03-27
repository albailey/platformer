// These are the C code settings for the platformer

#include "../examples/example1.h"

// Uncomment the following line to see a horizontal line on the screen to indicate CPU cycles remaining per frame
#define DEV_MODE 1

// Fixed point math (assuming the bottom 4 bits are the decimal)
// 16              = 00010000 ==  1.0
// 16 + 8          = 00011000 =>  1.5
// 16 + 8 + 4 + 2  = 00011110 ~=> 1.9
// Use Friction 1.9 (30)
#ifndef FRICTION
#define FRICTION 30
#endif

// Use Acceleration of 1.0 (16)
#ifndef ACCELERATION
#define ACCELERATION 16
#endif

// Use Max velocity of 6.5 (64+32+0+8)
#ifndef MAX_VELOCITY
#define MAX_VELOCITY 104
#endif

#ifndef MIN_VELOCITY
#define MIN_VELOCITY -104
#endif








