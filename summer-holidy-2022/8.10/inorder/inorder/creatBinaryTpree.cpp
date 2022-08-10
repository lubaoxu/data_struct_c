#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "data.h"
#include "inorder.h"

Data* createTreeNode(char cPoint)
{
	Data* pNode = (Data*)malloc(sizeof(Data));
	pNode->pLeftChild = NULL;
	pNode->pRightChild = NULL;
	pNode->pParent = NULL;
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

void createBinaryTpree()
{
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
	pSecondNode->pParent = pFirstNode;

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
	inorder(pFirstNode);
}

void destoryBinaryTree() {
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