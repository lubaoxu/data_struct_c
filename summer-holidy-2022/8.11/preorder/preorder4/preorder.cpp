#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "data.h"
#include "stack.h"

void preorder(Data* pFirstNode)
{
	Stack* pStack = (Stack*)malloc(sizeof(Stack));
	initializeStack(pStack);

	Data* pCurrentNode = pFirstNode;
	int loopCount = 0;

	while (pCurrentNode != NULL)
	{
		printf("第 %d 轮循环 begin %c\n", ++loopCount, pCurrentNode->cPoint);
		if (pCurrentNode->nFlag == 0)
		{
			printf("%c", pCurrentNode->cPoint);
			pushStack(pStack, pCurrentNode->pRightChild);
			pCurrentNode = pCurrentNode->pLeftChild;
			pCurrentNode->nFlag = 1;
		}
		if (pCurrentNode->nFlag == 1)
		{
			printf("%c", pCurrentNode->cPoint);
			pCurrentNode->nFlag = 2;
			if (pCurrentNode->pLeftChild != NULL)
			{
				pCurrentNode = pCurrentNode->pLeftChild;
			}
		}

		if (pCurrentNode != NULL)
		{
			char var = pCurrentNode->cPoint;
			printf("第 %d 轮循环 end %c\n\n", loopCount, var);
		}
		else
		{
			printf("第 %d 轮循环 end \n\n", loopCount);
		}

	}
	
}