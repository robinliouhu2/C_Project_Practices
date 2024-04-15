#pragma once
#include <graphics.h>
#include "time.h"

typedef enum { PLAYER, BULLET, ENEMY }GameObjType;
typedef enum { DEAD,LIVE }GameObjState;

typedef struct
{
	GameObjState state;
	GameObjType  type;
	int pos_x;
	int pos_y;
	int speed_x;
	int speed_y;
	int img_index;
}GameObj;

typedef struct
{
	GameObj word_objs[100];
	bool   isEnd;
	clock_t current_time;
}GAME_WORDDATA;

typedef struct
{
	int win_wid;
	int win_hei;
	int margin;
	int gameImg_wid;
	int gameImg_hei;
	int gameObj_maxSpeed;
	int player_speed;
	int bullet_speed;
	int gameObj_number;
	int enemy_born_interval; // millionseconds 
	int player_fire_interval;
}GAME_SETTING;

#define ENEMY_NUM 5

typedef struct
{
	IMAGE bgRunning;
	IMAGE bgEnd;
	IMAGE player;
	IMAGE bullet;
	IMAGE Enemy[ENEMY_NUM];
}GAME_IMGS;



