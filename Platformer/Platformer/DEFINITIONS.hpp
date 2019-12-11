#pragma once


#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 800

#define PLAYER_ACC 0.8
#define PLAYER_FRIC -0.12
#define PLAYER_GRAV 0.7
#define PLAYER_JUMP 18

#define PLATFORM_MAX_LENGTH 200
#define PLATFORM_MIN_LENGTH 100
#define PLATFORM_MAX_HEIGHT 50
#define PLATFORM_MIN_HEIGHT 30



enum PLAYERSTATE {
	STAND, WALK, JUMP
};
