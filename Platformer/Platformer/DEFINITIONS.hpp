#pragma once


#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 800

#define PLAYER_ACC 0.8
#define PLAYER_FRIC -0.12
#define PLAYER_GRAV 0.7
#define PLAYER_JUMP 18

#define CAMERA_SPEED 10.0f

#define PLATFORM_MAX_LENGTH 250
#define PLATFORM_MIN_LENGTH 150
#define PLATFORM_MAX_HEIGHT 80
#define PLATFORM_MIN_HEIGHT 65

#define SPRITESHEET "images/Spritesheet.png"
#define GAME_FONT "fonts/PusabFont.otf"



enum PLAYERSTATE {
	STAND, WALK, JUMP
};
