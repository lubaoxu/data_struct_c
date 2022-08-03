#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define  MAX_COUNT 100

struct Data
{
	char cPoint;
	Data* pLeftChild;
	Data* pRightChild;
	Data* pParent;
};

typedef struct tagStackData
{
	int nTop;
	int Bottom;
	Data* pDataArray;
	int nCapacity;
}Stack;

Data* creatTreeNode(char cPoint)
{
	Data* pNode = (Data*)malloc(sizeof(Data));
	pNode->pLeftChild = NULL;
	pNode->pRightChild = NULL;
	pNode->cPoint = cPoint;
	return pNode;
}

void initializeStack(Stack* pStack)
{
	pStack->nTop = NULL;
	pStack->Bottom = NULL;
	int nMemSize = MAX_COUNT * sizeof(Data);
	pStack->pDataArray = (Data*)malloc(nMemSize);
	pStack->nCapacity = nMemSize;
}

void pushStack(Stack* pStack, Data* pNode)
{
	(pStack->pDataArray[pStack->nTop]) = *pNode;
	pStack->nTop++;
}

Data* popStack(Stack* pStack)
{
	if (pStack->nTop == NULL)
	{
		return 0;
	}
	pStack->nTop--;
	Data* data = &(pStack->pDataArray[pStack->nTop]);
	return data;
}



void preOrder(Data* pFirstNode)
{
	Stack* pStack = (Stack*)malloc(sizeof(Stack));
	initializeStack(pStack);

	Data* pCurrentNode = pFirstNode;
	int loopCount = 0;
	
	while (pCurrentNode != NULL)
	{
		if (pCurrentNode == NULL)
		{
			break;
		}
		printf("第 %d 轮循环 begin %c\n", ++loopCount,pCurrentNode->cPoint);
		if (pCurrentNode->pLeftChild != NULL)
		{
			pushStack(pStack, pCurrentNode);
			pCurrentNode = pCurrentNode->pLeftChild;
		}
		else
		{
			
			while (pCurrentNode->pRightChild == NULL)
			{
				printf("%c\n", pCurrentNode->cPoint);
				pCurrentNode = popStack(pStack);
				if (pCurrentNode == NULL)
				{
					break;
				}
			}
			if (pCurrentNode == NULL)
			{
				break;
			}
			if (pCurrentNode->pRightChild != NULL)
			{
				printf("%c\n", pCurrentNode->cPoint);
				pCurrentNode = pCurrentNode->pRightChild;
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

int main()
{
	Data* pFirstNode = creatTreeNode('A');
	Data* pSecondNode = creatTreeNode('B');
	Data* pThirdNode = creatTreeNode('C');
	Data* pFourthNode = creatTreeNode('D');
	Data* pFifthNode = creatTreeNode('E');
	Data* pSixthNode = creatTreeNode('F');
	Data* pSeventhNode = creatTreeNode('G');

	pFirstNode->pLeftChild = pSecondNode;
	pSecondNode->pParent = pFirstNode;

	pFirstNode->pRightChild = pThirdNode;
	pThirdNode->pParent = pFirstNode;

	pSecondNode->pLeftChild = pFourthNode;
	pFourthNode->pParent = pSecondNode;

	pSecondNode->pRightChild = pFifthNode;
	pFifthNode->pParent = pSecondNode;

	pThirdNode->pRightChild = pSixthNode;
	pSixthNode->pParent = pThirdNode;

	pFifthNode->pRightChild = pSeventhNode;
	pSeventhNode->pParent = pFifthNode;

	printf("%c\t%c\t%c\t%c\t%c\t%c\t%c\n\n", pFirstNode->cPoint, pSecondNode->cPoint, pThirdNode->cPoint, pFourthNode->cPoint, pFifthNode->cPoint, pSixthNode->cPoint, pSeventhNode->cPoint);

	preOrder(pFirstNode);

	return 0;
}