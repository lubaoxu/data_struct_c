// swap.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

//#pragma warning(disable:6011)


#include <iostream>
#include <string.h>
#include <stdio.h>

struct SwapData {
	int element;
	SwapData* pNext;
};

void outputLink(SwapData* node)
{
	while (node != NULL)
	{
		printf("%d %x\n", node->element, node->element);
		node = node->pNext;
	}
}
	


int main()
{
	SwapData* swapHead = NULL;
	SwapData* swapEnd = NULL;
	for (int i = 0; i < 10; i++)
	{
		SwapData* swapA = (SwapData*)malloc(sizeof(SwapData));
		//swapA = NULL;
		if (swapA) {
			swapA->element = i ;
			swapA->pNext = NULL;
			if (i == 0)
			{
				swapHead = swapA;
			}
			else
			{
				swapEnd->pNext = swapA;
			}
		}
		swapEnd = swapA;
	}
	outputLink(swapHead);

	SwapData* pThirdNode = NULL;
	SwapData* pSecondNode = NULL;
	SwapData* Eighth = NULL;
	SwapData* Seventh = NULL;
	SwapData* Sixth = NULL;
	SwapData* current = swapHead;
	int i = 0;
	while (current != NULL)
	{
		if (i == 1)
		{
			pSecondNode = current;
		}
		else if (i == 2)
		{
			pThirdNode = current;
			
		}
		else if (i == 6)
		{
			Sixth = current;
		}
		else if (i == 7)
		{
			Seventh = current;
		}
		else if (i == 8)
		{
			Eighth = current;
		}
		
		current = current->pNext;
		i++;

	}
	pSecondNode->pNext = Seventh;
	Seventh->pNext = pThirdNode->pNext;
	Sixth->pNext = pThirdNode;
	pThirdNode->pNext = Eighth;
	printf("交换后：\n");
	outputLink(swapHead);
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
