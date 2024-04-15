#include "AI.h"

/*
源码为 C语言工程实践 课程配套代码，
如需获取 课程链接 或 加学习交流群
请搜索微信号 cpproad 备注 C语言学习
*/

void AI_Control()
{
	static clock_t last_born_time = 0;

	if (g_WordData.current_time - last_born_time > g_GameSetting.enemy_born_interval)
	{
		CreateEnemy();
		last_born_time = g_WordData.current_time;
	}
}