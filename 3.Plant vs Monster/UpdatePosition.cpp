/*
源码为 C语言工程实践 课程配套代码，
如需获取 课程链接 或 加学习交流群
请搜索微信号 cpproad 备注 C语言学习
*/

#include "UpdatePosition.h"

void Restrict_Player_Pos(GameObj* pPlayer)
{
	if (pPlayer->pos_x < 0)
	{
		pPlayer->pos_x = 0;
	}
	else if (pPlayer->pos_x > g_GameSetting.win_wid)
	{
		pPlayer->pos_x = g_GameSetting.win_wid;
	}

	if (pPlayer->pos_y < 0)
	{
		pPlayer->pos_y = 0;
	}
	else if (pPlayer->pos_y > g_GameSetting.win_hei)
	{
		pPlayer->pos_y = g_GameSetting.win_hei;
	}
}


void Update_GameObj_Position(GameObj* pObjs, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		GameObj* pCur = &pObjs[i];
		if (pCur->state == LIVE)
		{
			pCur->pos_x += pCur->speed_x;
			pCur->pos_y += pCur->speed_y;
		}
	}

	//player 总是总是第一个被创建
	Restrict_Player_Pos(&pObjs[0]);
}

