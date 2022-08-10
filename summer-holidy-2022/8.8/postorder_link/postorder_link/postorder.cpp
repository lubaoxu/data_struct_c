#include <stdlib.h>
#include <stdio.h>

#include "data.h"
#include "stack.h"

int g_j = 100;

void postorder(Data* pFirstNode)
{
	Stack* pStack1 = (Stack*)malloc(sizeof(Stack));
	initializeStack(pStack1);

	Stack* pStack2 = (Stack*)malloc(sizeof(Stack));
	initializeStack(pStack2);

	Data* pCurrentNode = pFirstNode;

	Data* pLastVisitedNode = NULL;

	Data* pCurrentNode2 = NULL;
	int loopCount = 0;

	while (pCurrentNode != NULL)
	{
		printf("第 %d 轮循环 begin %c\n", ++loopCount, pCurrentNode->cPoint);

		if (pCurrentNode->pLeftChild != NULL)
		{
			pushStack(pStack1, pCurrentNode);
			pCurrentNode = pCurrentNode->pLeftChild;
		}
		else if (pCurrentNode->pRightChild != NULL)
		{
			pushStack(pStack1, pCurrentNode);
			pCurrentNode = pCurrentNode->pRightChild;
		}
		else
		{
			while (pCurrentNode != NULL)
			{
				if (pCurrentNode->pRightChild == NULL ||
					(pLastVisitedNode != NULL && pCurrentNode->pRightChild->cPoint == pLastVisitedNode->cPoint))
				{
					printf("%c\n", pCurrentNode->cPoint);
					pLastVisitedNode = pCurrentNode;
					pCurrentNode = popStack(pStack1);
				}
				else {
					Data* pTemp = pCurrentNode;
					pCurrentNode = pCurrentNode->pRightChild;
					pushStack(pStack1, pTemp);
					break;
				}
			}
		}

		if (pCurrentNode != NULL)
		{
			char var = pCurrentNode->cPoint;
			printf("第 %d 轮循环 end %c \n\n", loopCount, var);
		}
		else
		{
			printf("第 %d 轮循环 end \n\n", loopCount);
		}
	} // end while

	unInitializeStack(pStack1);
	free(pStack1);
}
