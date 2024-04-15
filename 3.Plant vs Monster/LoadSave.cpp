#define  _CRT_SECURE_NO_WARNINGS
#include "LoadSave.h"
#include "stdio.h"
#include <assert.h>

const char* g_pathName = "worddata.bin";

void Save_Word()
{
	FILE* pFile = fopen(g_pathName, "wb");  
	if (pFile != NULL)
	{
		size_t writeElements = fwrite(&g_WordData,sizeof(GAME_WORDDATA),1, pFile);
		fclose(pFile);
		
		assert(writeElements!=0);
		return;
	}	
	
	printf("file open failed %s\n", g_pathName);
}

void Load_Word()
{
	FILE* pFile = fopen(g_pathName, "rb"); //"rb"
	if (pFile != NULL)
	{
		size_t readElements = fread(&g_WordData, sizeof(GAME_WORDDATA), 1, pFile);
		assert(readElements != 0);
		fclose(pFile);
		return;
	}

	printf("file open failed %s\n", g_pathName);
}

void Word_Control()
{
	if (GetAsyncKeyState(VK_F1))
	{
		Save_Word();
	}
	else if (GetAsyncKeyState(VK_F2))
	{
		Load_Word();
	}
}

/*
源码为 C语言工程实践 课程配套代码，
如需获取 课程链接 或 加学习交流群
请搜索微信号 cpproad 备注 C语言学习
*/