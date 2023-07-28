// 102_8.5结构体数组应用之选票系统.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "102_8.5结构体数组应用之选票系统.h"

struct XuanMin
{
	char name[32];
	int tickets;
};


int main()
{
	struct XuanMin xm[3];
	struct XuanMin max;
	int i;
	int j;
	int len;
	int mark;
	char tmpName[32] = { '\0' };
	int feipiao=0;
	

	//初始化选民信息
	len = sizeof(xm) / sizeof(xm[0]);
	for (i = 0; i < len; i++)
	{
		xm[i].tickets = 0;
		printf("请输入第%d个选民的名字\n",i+1);
		scanf_s("%s", &xm[i].name, sizeof(xm[i].name));
	}

	//唱票环节
	for (i = 0; i < 5; i++)
	{
		mark = 0;
		printf("请输入你投给谁:\n");
		memset(tmpName, '\0', sizeof(tmpName));
		scanf_s("%s", &tmpName,sizeof(tmpName));
		for (j = 0; j < len; j++)
		{
			if (strcmp(tmpName, xm[j].name) == 0)
			{
				xm[j].tickets += 1;
				mark = 1;
			}
		}
		if (mark == 0)
		{
			printf("没有此候选人，放弃\n");
			feipiao++;

		}
	}

	//公示结果
	for (i = 0; i < len; i++)
	{
		printf("名字:%s,票数:%d,\n", xm[i].name, xm[i].tickets);
	}

	max = xm[0];
	for (i = 1; i < len; i++)
	{
		if (max.tickets < xm[i].tickets)
		{
			max.tickets = xm[i].tickets;
		}
	}
	printf("%s以%d票当选！！ 废票是%d\n", max.name,max.tickets, feipiao);

	return 0;
}
