// swap.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include<stdlib.h>
#include <iostream>
#include <string.h>
#include <stdio.h>
struct swap {
	int element;
	swap* Next;
};
void p(swap* node)
{
	while (node != NULL)
	{
		printf("%d %x\n", node->element, node->element);
		node = node->Next;
	}
}
int main()
{
	swap* swapHead = NULL;
	swap* swapEnd = NULL;
	for (int i = 0; i < 10; i++)
	{
		swap* swapA = (swap*)malloc(sizeof(swap));
		swapA->element = i + 1;
		swapA->Next = NULL;
		if (i == 0)
		{
			swapHead = swapA;
		}
		else
		{
			swapEnd->Next = swapA;
		}
		swapEnd = swapA;
	}
	p(swapHead);
	swap* First = NULL;
	swap* Second = NULL;
	swap* Ninth = NULL;
	swap* Tenth = NULL;
	swap* current = swapHead;
	int i = 0;
	while (current != NULL)
	{
		if (i == 0)
		{
			First = current;
		}
		else if (i == 1)
		{
			Second = current;

		}
		else if (i == 8)
		{
			Ninth = current;
		}
		else if (i == 9)
		{
			Tenth = current;
		}
		current = current->Next;
		i++;
	}
	 swapHead=Tenth;
	 Tenth->Next = Second;
	 Ninth->Next = First;
	 First->Next = NULL;

	printf("交换后：\n");
	p(swapHead);
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
