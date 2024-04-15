#pragma once
#include "TypeDef.h"

extern GAME_SETTING g_GameSetting;
extern GAME_WORDDATA g_WordData;

GameObj* CreatePlayer();
GameObj* CreateBullet(GameObj* pPlayer);
GameObj* CreateEnemy();



