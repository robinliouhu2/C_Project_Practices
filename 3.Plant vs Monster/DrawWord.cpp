/*
源码为录播课程C语言工程实践配套代码，
如需获取课程链接或加学习交流群
请搜索微信号 cpproad 加好友说明需求
*/
#include "DrawWord.h"
#include <assert.h>
#pragma comment(lib,"MSIMG32.LIB")

GAME_IMGS g_imgs;

IMAGE* get_obj_img(GameObj* pObj)
{
	if (pObj->type == PLAYER)
	{
		return &g_imgs.player;
	}
	else if (pObj->type == BULLET)
	{
		return &g_imgs.bullet;
	}
	else if (pObj->type == ENEMY)
	{
		return &g_imgs.Enemy[ pObj->img_index];
	}

	assert(false);
	return NULL;
}

#include <math.h>

void Draw_Word(GameObj* pObjs,int size)
{
	//绘制背景
	Putimage_2(0,0, g_WordData.isEnd ? &g_imgs.bgEnd : &g_imgs.bgRunning );

	//遍历绘制游戏世界中所有的角色
	for (size_t i = 0; i < size; i++)
	{
		GameObj* pCur = &pObjs[i];
		if (pCur->state == LIVE )
		{
			int draw_x = pCur->pos_x - g_GameSetting.gameImg_wid / 2;
			int draw_y = pCur->pos_y - g_GameSetting.gameImg_hei / 2;

			Putimage_2(draw_x, draw_y, get_obj_img(pCur));
		}
	}
}

void Load_Imgs()
{
	GAME_IMGS* pIMGS = &g_imgs;

	loadimage(&pIMGS->bgRunning, "./imgs/bg.jpg",g_GameSetting.win_wid,g_GameSetting.win_hei,true);
	loadimage(&pIMGS->bgEnd, "./imgs/end.jpg", g_GameSetting.win_wid, g_GameSetting.win_hei, true);
	loadimage(&pIMGS->player, "./imgs/p.png");
	loadimage(&pIMGS->bullet, "./imgs/b.png");
	loadimage(&pIMGS->Enemy[0], "./imgs/e1.png");
	loadimage(&pIMGS->Enemy[1], "./imgs/e2.png");
	loadimage(&pIMGS->Enemy[2], "./imgs/e3.png");
	loadimage(&pIMGS->Enemy[3], "./imgs/e4.png");
	loadimage(&pIMGS->Enemy[4], "./imgs/e5.png");
}


//easyx 提供的 putimage 函数不支持透明图片的混合，所以增加自定义函数支持透明图片的绘制
void Putimage_2(int x, int y, IMAGE* pImg)
{
	HDC dstDC = GetImageHDC(NULL);
	HDC srcDC = GetImageHDC(pImg);
	int w = pImg->getwidth();
	int h = pImg->getheight();
	BLENDFUNCTION blendFn = { AC_SRC_OVER,0,255,AC_SRC_ALPHA };

	AlphaBlend(dstDC, x, y, w, h, srcDC, 0, 0, w, h, blendFn);
}