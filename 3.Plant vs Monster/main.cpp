#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include "DrawWord.h"
#include "TypeDef.h"
#include "GameWord.h"
#include "PlayerControl.h"
#include "UpdatePosition.h"
#include "AI.h"
#include "UpdateDamage.h"
#include "LoadSave.h"

void init()
{
	g_GameSetting.win_wid = 1500;
	g_GameSetting.win_hei = 800;
	g_GameSetting.gameImg_hei = 200;
	g_GameSetting.gameImg_wid = 200;
	g_GameSetting.margin = 100;
	g_GameSetting.gameObj_maxSpeed = 15;
	g_GameSetting.player_speed = 5;
	g_GameSetting.bullet_speed = 15;
	g_GameSetting.gameObj_number = (sizeof(g_WordData.word_objs) / sizeof(GameObj));
	g_GameSetting.enemy_born_interval = 200; 
	g_GameSetting.player_fire_interval = 100;

	memset(&g_WordData,0,sizeof(g_WordData));


	initgraph(g_GameSetting.win_wid, g_GameSetting.win_hei);
	srand((unsigned int)time(NULL));
	Load_Imgs();

	CreatePlayer();
}

void deInit()
{
	closegraph();
}

/*
源码为 C语言工程实践 课程配套代码，
如需获取 课程链接 或 加学习交流群
请搜索微信号 cpproad 备注 C语言学习
*/
int main()
{
	init();
	BeginBatchDraw();
	
	// 帧率(每秒钟绘制/循环 多少次画面)  1s 60帧画面流畅  低于30帧会卡顿
	while (true)//esc 
	{

		if (!g_WordData.isEnd)
		{
			g_WordData.current_time = clock();
			Player_Control();
			AI_Control();
			
			Update_GameObj_Position(g_WordData.word_objs, g_GameSetting.gameObj_number);
			UpdateDamage(g_WordData.word_objs, g_GameSetting.gameObj_number);
		}

		Word_Control();
		Draw_Word(g_WordData.word_objs, g_GameSetting.gameObj_number);
		FlushBatchDraw();
		Sleep(10);//millionseconds
	}
	EndBatchDraw();
	deInit();
}

