#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_COUNT 100

struct Data {
	char cPoint;
	Data* pLeftChild;
	Data* pRightChild;
	Data* pParent;
	int nFlag;
};

typedef struct tagStackData
{
	int nTop;
	int Bottom;
	Data* pDataArray;
	int nCapacity;
}Stack;

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
	Data* pData = &(pStack->pDataArray[pStack->nTop]);
	return pData;
}

void unInitializeStack(Stack* pStack)
{
	free(pStack->pDataArray);
	pStack->pDataArray = NULL;
}

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
			while (pCurrentNode != NULL )
			{
				if (pCurrentNode->pRightChild == NULL || 
					(pLastVisitedNode!=NULL && pCurrentNode->pRightChild->cPoint == pLastVisitedNode->cPoint))
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

Data* createTreeNode(char cPoint)
{
	Data* pNode = (Data*)malloc(sizeof(Data));
	pNode->pLeftChild = NULL;
	pNode->pRightChild = NULL;
	pNode->nFlag = 0;
	pNode->cPoint = cPoint;
	return pNode;
}

static Data* pFirstNode = NULL;
static Data* pSecondNode = NULL;
static Data* pThirdNode = NULL;
static Data* pFourthNode = NULL;
static Data* pFifthNode = NULL;
static Data* pSixthNode = NULL;
static Data* pSeventhNode = NULL;
static Data* pEighthNode = NULL;
static Data* pNinthNode = NULL;
static Data* pTenthNode = NULL;
static Data* pEleventhNode = NULL;
static Data* pTwelfthNode = NULL;
static Data* pThirteenthNode = NULL;
static Data* pFourteenthNode = NULL;

void createBinaryTpree() {
	pFirstNode = createTreeNode('A');
	pSecondNode = createTreeNode('B');
	pThirdNode = createTreeNode('C');
	pFourthNode = createTreeNode('D');
	pFifthNode = createTreeNode('E');
	pSixthNode = createTreeNode('F');
	pSeventhNode = createTreeNode('G');
	pEighthNode = createTreeNode('H');
	pNinthNode = createTreeNode('I');
	pTenthNode = createTreeNode('J');
	pEleventhNode = createTreeNode('K');
	pTwelfthNode = createTreeNode('L');
	pThirteenthNode = createTreeNode('M');
	pFourteenthNode = createTreeNode('N');

	(pFirstNode)->pLeftChild = pSecondNode;
	(pSecondNode)->pParent = pFirstNode;

	(pFirstNode)->pRightChild = pThirdNode;
	(pThirdNode)->pParent = pFirstNode;

	(pSecondNode)->pLeftChild = pFourthNode;
	(pFourthNode)->pParent = pSecondNode;

	(pSecondNode)->pRightChild = pFifthNode;
	(pFifthNode)->pParent = pSecondNode;

	(pThirdNode)->pRightChild = pSixthNode;
	(pSixthNode)->pParent = pThirdNode;

	(pFifthNode)->pRightChild = pSeventhNode;
	(pSeventhNode)->pParent = pFifthNode;

	(pSeventhNode)->pLeftChild = pEighthNode;
	(pEighthNode)->pParent = pSeventhNode;

	(pSeventhNode)->pRightChild = pNinthNode;
	(pNinthNode)->pParent = pSeventhNode;

	(pEighthNode)->pLeftChild = pTenthNode;
	(pTenthNode)->pParent = pEighthNode;

	(pEighthNode)->pRightChild = pEleventhNode;
	(pEleventhNode)->pParent = pEighthNode;

	(pNinthNode)->pRightChild = pTwelfthNode;
	(pTwelfthNode)->pParent = pNinthNode;

	(pEleventhNode)->pRightChild = pThirteenthNode;
	(pThirteenthNode)->pParent = pEleventhNode;

	(pThirteenthNode)->pRightChild = pFourteenthNode;
	(pFourteenthNode)->pParent = pThirteenthNode;
}

void destroyBinaryTree() {
	free(pFirstNode);
	free(pSecondNode);
	free(pThirdNode);
	free(pFourthNode);
	free(pFifthNode);
	free(pSixthNode);
	free(pSeventhNode);
	free(pEighthNode);
	free(pNinthNode);
	free(pTenthNode);
	free(pEleventhNode);
	free(pTwelfthNode);
	free(pThirteenthNode);
	free(pFourteenthNode);
	pFirstNode = NULL;
	pSecondNode = NULL;
	pThirdNode = NULL;
	pFourthNode = NULL;
	pFifthNode = NULL;
	pSixthNode = NULL;
	pSeventhNode = NULL;
	pEighthNode = NULL;
	pNinthNode = NULL;
	pTenthNode = NULL;
	pEleventhNode = NULL;
	pTwelfthNode = NULL;
	pThirteenthNode = NULL;
	pFourteenthNode = NULL;
}

int main()
{
	createBinaryTpree();
	printf("%c\t%c\t%c\t%c\t%c\t%c\t%c\t%c\t%c\t%c\t%c\t%c\t%c\t%c\t%c\n", pFirstNode->cPoint, pSecondNode->cPoint,
		pThirdNode->cPoint, pFourthNode->cPoint, pFifthNode->cPoint, pSixthNode->cPoint, pSeventhNode->cPoint, pEighthNode->cPoint
		, pNinthNode->cPoint, pTenthNode->cPoint, pEleventhNode->cPoint, pTwelfthNode->cPoint, pThirteenthNode->cPoint,
		pFourteenthNode->cPoint);

	postorder(pFirstNode);

	destroyBinaryTree();
	return 0;
}