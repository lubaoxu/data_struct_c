// acceptance.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string.h>
#include <stdio.h>
struct acceptance {
	int element;
	acceptance* Next;
};
void p(acceptance* node)
{
	while (node != NULL)
	{
		printf("%d %x\n", node->element, node->element);
		node = node->Next;
	}
}
int main()
{
	acceptance* acceptanceHead = NULL;
	acceptance* acceptanceEnd = NULL;
	for (int i = 0; i < 10; i++)
	{
		acceptance* acceptanceA = (acceptance*)malloc(sizeof(acceptance));
		acceptanceA->element = i+1;
		acceptanceA->Next = NULL;
		if (i == 0)
		{
			acceptanceHead = acceptanceA;
		}
		else
		{
			acceptanceEnd->Next = acceptanceA;
		}
		acceptanceEnd = acceptanceA;
	}
	 p(acceptanceHead);
	 acceptance* Third = NULL;
	 acceptance* Fourth = NULL;
	 
	 acceptance* current = acceptanceHead;
	 int i = 0;
	 while(current!=NULL)
	 {
		 if (i == 2)
		 {
			 Third = current;
		 }
		 else if (i == 3)
		 {
			 Fourth = current;
			 break;
		 }
		 else
			 current = current->Next;
		 i++;
	 }
	 acceptance* Add = (acceptance*)malloc(sizeof(acceptance));
	 Add->element = 5;
	 Add->Next = NULL;
	 Add->Next = Third->Next;
	 Third->Next =Add ;
	 printf("插入后:\n");
	 p(acceptanceHead);
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
