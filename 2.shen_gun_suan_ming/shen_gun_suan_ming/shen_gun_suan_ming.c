/*
欢迎进入C语言学习交流群。 (搜索微信号 cpproad  ,备注 C语言进群)
*/

//为了教学简洁性，定义该宏以便允许使用scanf非安全版本函数,也可以修改IDE的配置，目前可以不做关注
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> //使用printf scanf 需要包含该头文件
#include <stdbool.h>//使用bool类型需要先包含该头文件
#include <string.h> //使用memset函数需要先包含该头文件
#include <math.h>



#define TEXTS_NUM 3   //定义一个宏变量，所有用到TEXTS_NUM 的地方，都会被替换为 3. 方便统一修改

const char* g_love_texts[TEXTS_NUM] = { "\n这样的你，有时还真的很滥情，在对象的选择上往往比较注重外表，也很注重感觉，如果感觉对了，你也可能一见钟情，对心仪的他马上示好。你浑身充满一股致命的吸引力，往往令人难以抗拒，也有可能成为别人的第三者，做出违背常理的不伦恋情。\n不过，你心中一旦有了心仪的对象，你较倾向采取主动攻势，任劳任怨的为对方付出，偶尔也会耍点小个性，随时会给对方惊喜，处理感情的时候，你很会打迷糊 仗，显得不清不楚的，有时好像不在乎，有时又好像没有对方不行。这种软硬兼施的爱情态度，有时甚至一而再再而三的发生，使人对你产生强烈的不安全感，通常 谈恋爱，也要谈很多次才可能有结果。",
								 "\n其实说穿了，你对于所喜爱的对象要求会比一般朋友来的高。 平时和情人容易闹点小脾气，有时还会将两人的事情，公开在死党好友面前。说话常常不经思考，对于爱恨很强烈，不太体谅另一半的感觉，有时爱情来的快，去的也快，如果得不到别人的尊重还会生气，个性古怪，对于所爱的人，会非常注意细节。\n感觉上跟你这样的人相处有些不易喔！其实你会用自己的方式来对待情人，如果对方个性上和你有许多共同点，你就比较能投其所好。不过，你很容易限制他人，喜欢干涉对方，你天生直肠子的性格，也容易造成与情人的口舌是非，虽然只是拌拌嘴、吐吐槽，不过和你交往，可能会有三天一小吵、五天一大吵的可能，越吵感情会越好，是一种打是情，骂是爱的欢喜冤家哦！",
								 "\n晚上有桃花运，偷着笑吧!"
};

const char* g_suanming_texts[TEXTS_NUM] = { "\n1、总论：这种很不幸的配置被您碰上了，中年以前不知要经过多少的挫折苦闷，又有急厄灾变要您去克服，漫长的黑夜总有过去的时候，拿出魄力及耐力，最后成功还是属于您的。\n2、性格：待人心性急，不耐独处生活，头脑急智活泼，举止优雅，易与异性接近，外柔而内刚，稍有固执之感。感情易冷易热，情绪很不稳定。\n3、意志：意志不够坚定，做事计划欠周详，但能忍耐失败的打击。\n4、事业：您的人生考验较长，中年前奔波劳苦，事业难顺利，中年后有成功机会，但须相当忍耐行事。\n5、家庭：与长上意见不和，夫妻一时圆满，终会离异或争执不休。\n6、婚姻：男娶好胜性急之妻，婚后幸福难持久；女嫁得过且过之夫，婚后常为小事而闹意见。\n7、子女：子女性格较孤独，身体状况不佳，与父母感情不融洽，长大后恐难靠。\n8、社交：喜好面子摆排场，性急易与人冲突，人缘不错，社交不甚圆满。\n9、精神：表面热情大方，其实精神不安，内心又苦闷，有苦说不出。\n10、财运：中年前经过很多苦劳或风波，中年后财源可得，但有不稳之兆，应注意防守。\n11、健康：易患头痛、心脏病、精神衰弱或分裂症、妇人病等，更有急病、遭难等危险。\n12、老运：晚景财源不缺，家庭多是非，精神烦闷不安。",
									 "\n1、总论：有才华，头脑灵敏，做事都经过仔细考虑，观察力强，信用也好，能发展成功之配置。但因数理有凶数，有家庭不幸或失败之倾向。天运五行有助者，名利可得。\n2、性格：善良优雅的个性，聪明又有判断力，但较为自私，花钱较小气，比较不注重物质生活，只想实现自己的理想，经历的考验较多。\n3、意志：意志坚定，为自己理想不断在奋斗，不浪费，耐性亦佳，能忍受艰苦。\n4、事业：有进取心，一生辛勤奋发，中年后可一展报复，事业有成。\n5、家庭：父母缘薄，夫妻不甚和睦，家庭不温暖。\n6、婚姻：男娶好胜好强之妻，婚后常有小争吵；女嫁才干之夫，婚后大致圆满。\n7、子女：子女个性较固执，身体较虚弱。\n8、社交：外缘好，社交普通，人际关系尚称圆满。\n9、精神：常有烦事来困扰，精神生活常在不安定中。\n10、财运：如能减少意外损失，如天运五行有助于外格及总格时，中年后财源丰富。\n11、健康：易患气喘、心脏病等。\n12、老运：终生辛劳，晚景难裕，但恐缺天伦之乐，身体也有病弱之象",
									 "\n啥都不说了，就是运气好!"
};

typedef enum { GOOD, NORMAL, BAD }Level;

typedef struct
{
	char name[100];//不知道名字长度，所以空间定义大一些 100
	float score;
	Level name_level;
	bool  is_love;
	union
	{
		int  love_index;
		int  suanming_index;
	}un;
}name_info;

Level get_level(float score)
{
	Level lv = GOOD;

	if (score < 30)
		return BAD;
	else if (score < 60)
		return NORMAL;

	return lv;
}


//通过名字计算对应的测算语句的下标索引
int get_index(char* pName)
{
	int number = 0;
	while ((*pName) != '\0') //字符串约定以'\0' 结尾,所以当前字符不是'\0'代表字符串尚未结束
	{
		number += (int)(*pName); //*去除指针指向位置的字符，然后通过（int）强转为整数（ascii码）
		++pName; //进入下一次循环前,将指针往前走一个字符
	}

	int index = number % TEXTS_NUM; // 取余，避免数组访问的索引超过数组总大小
	return abs(index); //返回索引 中文字符强转后可能为负数，所以取绝对值
}

//通过名字计算对应的分数
float get_score(char* pName)
{
	int number = 0;
	while ((*pName) != '\0') //字符串约定以'\0' 结尾,所以当前字符不是'\0'代表字符串尚未结束
	{
		number += (int)(*pName); //*去除指针指向位置的字符，然后通过（int）强转为整数（ascii码）
		++pName; //进入下一次循环前,将指针往前走一个字符
	}

	float score = (float)(abs(number) % 100); // 取余,使分数在0-100的范围内

	return score;
}

void print_result(name_info* pInfo)
{
	printf("您的姓名所得分数是 %f \n", pInfo->score);

	if (pInfo->is_love)
	{
		printf("\n您的爱情测算结果是:%s\n", g_love_texts[pInfo->un.love_index]);
	}
	else
	{
		printf("\n您的算命结果是:%s\n", g_suanming_texts[pInfo->un.suanming_index]);
	}

	printf("\n***********************************\n\n\n");
}

int main()
{
	name_info info;
	memset(&info, 0, sizeof(info)); // 初始化 将变量所在内存全部设置为0

	int inpute_number = 0;
	int action = 0;// 1.测爱情 2.测算命 0.退出

	printf("请输入大侠的名称:"); // \n 代表特殊字符 换行
	inpute_number = scanf("%s", info.name);//数组的名字就代表数组的首地址

	do {

		if (inpute_number > 0)
		{
			printf("请输入您要进行的操作 (1.测爱情 2.测算命 0.退出):");
			inpute_number = scanf("%d", &action);

			if ((inpute_number > 0) && (action != 0))
			{
				info.score = get_score(info.name);
				info.name_level = get_level(info.score);
				info.is_love = action == 1 ? true : false; //action != 0 才会执行到这里，因为前面有if判断

				if (info.is_love)
				{
					info.un.love_index = get_index(info.name);
				}
				else
				{
					info.un.suanming_index = get_index(info.name);
				}

				print_result(&info);//传递指针
			}
		}

	} while (action != 0);


	return 0;
}
