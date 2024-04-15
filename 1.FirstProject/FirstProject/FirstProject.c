//双斜杠后面的语句代表注释，给人看的，不会被编译执行

//为了教学简洁性，定义该宏以便允许使用scanf非安全版本函数,也可以修改IDE的配置，目前可以不做关注
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> //printf 函数在该头文件中被声明，必须包含后才能使用printf
#include <stdbool.h>//bool 类型在该头文件中被声明，必须包含后才能使用bool 类型

//打印第一个句子
void print_first_sentence(bool use_chinese)
{
	//定义一个装载用户名字的变量
	char user_name[100];

	//在控制台打印提示语句，提示用户进行输入
	printf("请输入大侠名称:");

	//从控制台接受用户输入，并存储在user_name变量中. 输入名字后，按enter键结束输入
	//为了保持简洁，暂时不对输入进行容错判断
	scanf("%s", user_name);

	char wish_sentence_0[] = "岂是池中物，一遇风云便化龙";
	char wish_sentence_1[] = "hello world!";

	if (use_chinese)
		printf("%s%s", user_name, wish_sentence_0);
	else
		printf("%s,%s", user_name, wish_sentence_1);
}

/*
如需进入C语言学习交流群 或 获取 C与语言工程实践课程链接 请搜索微信号 cpproad  备注 C语言学习
*/

//操作系统调用的第一个函数
int main() {
	//是否打印中文欢迎语句，考虑环境差异，碰到中文乱码的同学，可以设置为false
	bool use_chinese = true;

	//调用其它函数,函数没有被调用不会被运行
	print_first_sentence(use_chinese);


	while(true);//控制台程序在非调试环境运行会直接退出 该语句尚未学习,可不做关注

	return 0; //约定好的含义，0代表一切正常 非0代表发生了错误，返回之后程序结束
}
