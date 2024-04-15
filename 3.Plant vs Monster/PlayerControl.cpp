/*
源码为 C语言工程实践 课程配套代码，
如需获取 课程链接 或 加学习交流群
请搜索微信号 cpproad 备注 C语言学习
*/

#define  _CRT_SECURE_NO_WARNINGS
#include "PlayerControl.h"

void Player_Control()
{
	static clock_t  last_fire_time = 0;

	GameObj* pPlayer = &g_WordData.word_objs[0];

	if (pPlayer->state == DEAD)
	{
		g_WordData.isEnd = true;
		return;
	}

	pPlayer->speed_y = 0;
	pPlayer->speed_x = 0;

	if (GetAsyncKeyState(VK_UP))
	{
		pPlayer->speed_y =  0 - g_GameSetting.player_speed;
	}
	else if (GetAsyncKeyState(VK_DOWN))
	{
		pPlayer->speed_y = g_GameSetting.player_speed;
	}
	
	if (GetAsyncKeyState(VK_LEFT))
	{
		pPlayer->speed_x = 0 - g_GameSetting.player_speed;
	}
	else if (GetAsyncKeyState(VK_RIGHT))
	{
		pPlayer->speed_x = g_GameSetting.player_speed;
	}

	if (GetAsyncKeyState(VK_SPACE))
	{
		if (g_WordData.current_time - last_fire_time > g_GameSetting.player_fire_interval)
		{
			CreateBullet(pPlayer);
			last_fire_time = g_WordData.current_time;
		}
	}
}




