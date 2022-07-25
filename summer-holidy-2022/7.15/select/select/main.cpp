// select.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include "link.h"


void select_sort(int a[], int len)
{
	int i, j;
	int min_value;
	int min_pos;
	for (i = 0; i < len; i++)
	{
		min_value = a[i];
		min_pos = i;
		for (j = i + 1; j < len; j++)
		{
			if (a[j] < min_value)
			{
				min_value = a[j];
				min_pos = j;
			}
		}
		if (min_value < a[i])
		{
			a[min_pos] = a[i];
			a[i] = min_value;
		}
	}
} 

struct link {
	int i;
	int j;
	link* pNext;
	link* pPre;
};

int main(void)
{
	IntLinkData * intLinkDataA = (IntLinkData *)malloc(sizeof(intLinkDataA));
	intLinkDataA->value =0x123;
	intLinkDataA->pNext = (IntLinkData*)malloc(sizeof(intLinkDataA));
	intLinkDataA->pNext->value = 0x125;
	intLinkDataA->pNext->pNext = NULL;

	readIntLink(intLinkDataA);

	return 233;


	link* linkA = new link();
	linkA->i = 10;
	linkA->j = 20;
	linkA->pNext = new link();

	linkA->pNext->i = 100;
	linkA->pNext->j = 200;


	int i;
	int a[10] = { 50,30,57,82,41,23,69,12,85,14 };
	for (i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	select_sort(a, 10);
	for (i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
