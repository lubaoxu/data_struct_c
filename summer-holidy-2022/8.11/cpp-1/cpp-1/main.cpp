#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "stack.h"

void inorder(Data* pFirstNode)
{
	Stack* pStack = new Stack();
	pStack->initializeStack();

	Data* pCurrentNode = pFirstNode;
	int loopCount = 0;

	while (pCurrentNode != NULL)
	{
		printf("第 %d 轮循环 begin %c\n", ++loopCount, pCurrentNode->cPoint);
		if (pCurrentNode->pLeftChild != NULL)
		{
			pStack->pushStack(pCurrentNode);
			pCurrentNode = pCurrentNode->pLeftChild;
		}
		else
		{
			while (pCurrentNode != NULL && pCurrentNode->pRightChild == NULL)
			{
				printf("%c\n", pCurrentNode->cPoint);
				pCurrentNode = pStack->popStack();
			}
			if (pCurrentNode != NULL && pCurrentNode->pRightChild != NULL)
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
	} // end while

	pStack->unInitializeStack();
	pStack = NULL;

}

// 静态区  全局静态变量
Data* pFirstNode = NULL;
static Data* pSecondNode = NULL;
static Data* pThirdNode = NULL;
static Data* pFourthNode = NULL;
static Data* pFifthNode = NULL;
static Data* pSixthNode = NULL;
static Data* pSeventhNode = NULL;

Data* creatTreeNode(char cPoint)
{
	Data* pNode = (Data*)malloc(sizeof(Data));
	pNode->pLeftChild = NULL;
	pNode->pRightChild = NULL;
	pNode->cPoint = cPoint;
	return pNode;
}

void createBinaryTpree() {
	pFirstNode = creatTreeNode('A');
	pSecondNode = creatTreeNode('B');
	pThirdNode = creatTreeNode('C');
	pFourthNode = creatTreeNode('D');
	pFifthNode = creatTreeNode('E');
	pSixthNode = creatTreeNode('F');
	pSeventhNode = creatTreeNode('G');

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
}

void destroyBinaryTree() {
	free(pFirstNode); pFirstNode = NULL;
	free(pSecondNode); pSecondNode = NULL;
	free(pThirdNode); pThirdNode = NULL;
	free(pFourthNode); pFourthNode = NULL;
	free(pFifthNode); pFifthNode = NULL;
	free(pSixthNode); pSixthNode = NULL;
	free(pSeventhNode); pSeventhNode = NULL;
}

int main()
{
	createBinaryTpree();

	printf("%c\t%c\t%c\t%c\t%c\t%c\t%c\n\n", pFirstNode->cPoint, pSecondNode->cPoint, pThirdNode->cPoint, pFourthNode->cPoint, pFifthNode->cPoint, pSixthNode->cPoint, pSeventhNode->cPoint);

	inorder(pFirstNode);

	destroyBinaryTree();

	return 0;
}