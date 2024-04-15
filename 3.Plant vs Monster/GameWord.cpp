#include "GameWord.h"

GAME_SETTING g_GameSetting;
GAME_WORDDATA g_WordData;

GameObj* Find_unUsed_GameObj()
{
	for (int i = 0; i < 100; ++i)
	{
		GameObj* pCur = &g_WordData.word_objs[i];
		if (pCur->state == DEAD)
			return pCur;
	}

	return NULL;
}

GameObj* CreatePlayer()
{
	GameObj* pBorn = Find_unUsed_GameObj();
	if (pBorn != NULL)
	{
		pBorn->type = PLAYER;
		pBorn->state = LIVE;
		pBorn->pos_x = 0 + g_GameSetting.margin; // margin 
		pBorn->pos_y = g_GameSetting.win_hei / 2;
		pBorn->speed_x = 0;
		pBorn->speed_y = 0;
	}
	return pBorn;
}

GameObj* CreateBullet(GameObj* pPlayer)
{
	GameObj* pBorn = Find_unUsed_GameObj();
	if (pBorn != NULL)
	{
		pBorn->type = BULLET;
		pBorn->state = LIVE;
		pBorn->pos_x = pPlayer->pos_x + g_GameSetting.gameImg_wid;
		pBorn->pos_y = pPlayer->pos_y;
		pBorn->speed_x = g_GameSetting.bullet_speed;
		pBorn->speed_y = 0;
	}
	return pBorn;
}

GameObj* CreateEnemy()
{
	GameObj* pBorn = Find_unUsed_GameObj();
	if (pBorn != NULL)
	{
		pBorn->type = ENEMY;
		pBorn->state = LIVE;
		pBorn->pos_x = g_GameSetting.win_wid - g_GameSetting.margin;
		pBorn->pos_y =  (rand() % g_GameSetting.win_hei) - g_GameSetting.margin;
		pBorn->speed_x = 0 - (rand() % g_GameSetting.gameObj_maxSpeed + 1);
		pBorn->speed_y = 0;
		pBorn->img_index = rand() % ENEMY_NUM;
	}
	return pBorn;
}

/*
源码为 C语言工程实践 课程配套代码，
如需获取 课程链接 或 加学习交流群
请搜索微信号 cpproad 备注 C语言学习
*/