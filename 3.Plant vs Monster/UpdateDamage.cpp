#include "UpdateDamage.h"
/*
源码为 C语言工程实践 课程配套代码，
如需获取 课程链接 或 加学习交流群
请搜索微信号 cpproad 备注 C语言学习
*/

void UpdateIntersect(GameObj* pObjs, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		GameObj* pObj1 = &pObjs[i];

		for (size_t j = 0; j < size; j++)
		{
			GameObj* pObj2 = &pObjs[j];
			if (pObj1 != pObj2 &&  // 自己和自己不检测相交
				pObj1->type != pObj2->type &&  //同一个类型的角色不检测相交
				(pObj1->state == LIVE && pObj2->state == LIVE) ) //不检测DEAD角色
			{
				int dx = abs(pObj1->pos_x - pObj2->pos_x);
				int dy = abs(pObj1->pos_y - pObj2->pos_y);

				if (dx < g_GameSetting.gameImg_wid/2 && dy < g_GameSetting.gameImg_hei/2)
				{
					pObj1->state = DEAD;
					pObj2->state = DEAD;
				}

			}
		
		}
	}
}

void UpdateOutOfWindow(GameObj* pObjs, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		GameObj* pCur = &pObjs[i];
		if (pCur->pos_x < 0 || pCur->pos_x > g_GameSetting.win_wid ||
			pCur->pos_y < 0 || pCur->pos_y > g_GameSetting.win_hei)
		{
			pCur->state = DEAD;
		}
	}
}

void UpdateDamage(GameObj* pObjs, int size)
{
	UpdateIntersect(pObjs,size);
	UpdateOutOfWindow(pObjs,size);
}