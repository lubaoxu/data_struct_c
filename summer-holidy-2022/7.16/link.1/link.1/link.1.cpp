// link.1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct library
{
	int books;
	int bookrack;
	library* Next;
};
void readlibrary(library*link)
{
	while (link != NULL)
	{
		printf("%d,%x %d %x\n",link->books,link->books,link->bookrack,link->bookrack );
		link = link->Next;
	}

}

int main()
{
	int i;
	library* libraryHead=NULL;
	library* libraryLast = NULL;

	for (i = 0; i < 100; i++)
	{
		// 1: 构建一个新的链表节点  node
		library* libraryB = (library*)malloc(sizeof(library));
		libraryB->books = i+1;
		libraryB->bookrack = i + 1;
		libraryB->Next = NULL;

		// 2: 插入到链表中  Head
		if (i==0)
		{
			libraryHead = libraryB;
		}
		else
		{
			libraryLast->Next = libraryB;
		}

		// 3: 更新标为节点
		libraryLast = libraryB;
	}

	// 4: 遍历链表
	readlibrary(libraryHead);
	
	return 0;

	library* libraryA = (library*)malloc(sizeof(libraryA));
	libraryA->books = 0x101;
	libraryA->bookrack = 0x102;
	libraryA->Next = (library*)malloc(sizeof(libraryA));
	libraryA->Next->books = 0x200;
	libraryA->Next->bookrack = 0x201;
	libraryA->Next->Next = (library*)malloc(sizeof(libraryA));
	libraryA->Next->Next->books= 0x301;
	libraryA->Next->Next->bookrack = 0x302;
	libraryA->Next->Next->Next = (library*)malloc(sizeof(libraryA));
	libraryA->Next->Next->Next->books = 0x401;
	libraryA->Next->Next->Next->bookrack = 0x402;
	libraryA->Next->Next->Next->Next = (library*)malloc(sizeof(libraryA));
	libraryA->Next->Next->Next->Next->books = 0x501;
	libraryA->Next->Next->Next->Next->bookrack = 0x502;
	libraryA->Next->Next->Next->Next->Next = (library*)malloc(sizeof(libraryA));
	libraryA->Next->Next->Next->Next->Next->books = 0x601;
	libraryA->Next->Next->Next->Next->Next->bookrack = 0x602;
	libraryA->Next->Next->Next->Next->Next->Next = (library*)malloc(sizeof(libraryA));
	libraryA->Next->Next->Next->Next->Next->Next->books = 0x701;
	libraryA->Next->Next->Next->Next->Next->Next->bookrack = 0x702;
	libraryA->Next->Next->Next->Next->Next->Next->Next = (library*)malloc(sizeof(libraryA));
	libraryA->Next->Next->Next->Next->Next->Next->Next->books = 0x801;
	libraryA->Next->Next->Next->Next->Next->Next->Next->bookrack = 0x802;
	libraryA->Next->Next->Next->Next->Next->Next->Next->Next= (library*)malloc(sizeof(libraryA));
	libraryA->Next->Next->Next->Next->Next->Next->Next->Next->books = 0x901;
	libraryA->Next->Next->Next->Next->Next->Next->Next->Next->bookrack = 0x902;
	libraryA->Next->Next->Next->Next->Next->Next->Next->Next->Next= (library*)malloc(sizeof(libraryA));
	libraryA->Next->Next->Next->Next->Next->Next->Next->Next->Next->books = 0x1001;
	libraryA->Next->Next->Next->Next->Next->Next->Next->Next->Next->bookrack = 0x1002;
	libraryA->Next->Next->Next->Next->Next->Next->Next->Next->Next->Next = NULL;

     readlibrary(libraryA);
	 return 0;
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
