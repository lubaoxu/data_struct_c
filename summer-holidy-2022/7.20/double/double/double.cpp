// double.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
struct Data{
	int iPoint;
	Data* pNext;
	Data* pPrevious;
};

void log(Data* pCurrentNode, char* stage)
{
	int iPrevious = -1;
	if (pCurrentNode != NULL && pCurrentNode->pPrevious != NULL)
	{
		iPrevious = pCurrentNode->pPrevious->iPoint;
	}
	int iCurrent = -1;
	if (pCurrentNode != NULL)
	{
		iCurrent = pCurrentNode->iPoint;
	}
	int iNext = -1;
	if (pCurrentNode != NULL && pCurrentNode->pNext != NULL)
	{
		iNext = pCurrentNode->pNext->iPoint;
	}
	printf("%s\t:previous:%d\tCurrent:%d\tNext:%d\t\n", stage, iPrevious, iCurrent, iNext);

}

void outputData(Data* pHead)
{
	printf("\n");
	Data* pCurrentNode = pHead;
	while (pCurrentNode != NULL)
	{
		//printf("%d\n", pCurrentNode->iPoint);
		log(pCurrentNode, (char*)"output");
		pCurrentNode = pCurrentNode->pNext;
	}
}

void reverseOutputData(Data* pTail)
{
	printf("\n");
	Data* pCurrentNode = pTail;
	while (pCurrentNode != NULL)
	{
		log(pCurrentNode, (char*)"reverseOutputData");
		//printf("%d\n", pCurrentNode->iPoint);
		pCurrentNode = pCurrentNode->pPrevious;
	}
}



int main()
{
	Data* pHead = NULL;
	Data* pTail = NULL;
	Data* pPreviousNode = NULL;
	for (int i = 1; i <= 10; i++)
	{
		Data* pCurrentNode = (Data*)malloc(sizeof(Data));
		pCurrentNode->pPrevious = NULL;
		pCurrentNode->iPoint = i;
		pCurrentNode->pNext = NULL;
		log(pCurrentNode, (char*) "begin");
		if (i == 1)
		{
			pHead = pCurrentNode;
		}
		else if (i == 10)
		{
			pTail = pCurrentNode;
		}
		if(i>1)
		{
			//正向挂接
			pPreviousNode->pNext = pCurrentNode;
			//pNextNode = pCurrentNode->pNext;
			
			//反向挂接
			pCurrentNode->pPrevious = pPreviousNode;
		}
		pPreviousNode = pCurrentNode;
		log(pCurrentNode,(char*)"End");
		

	}
	outputData(pHead);
	printf("逆序输出后：\n");
	reverseOutputData(pTail);
	return 0;
}