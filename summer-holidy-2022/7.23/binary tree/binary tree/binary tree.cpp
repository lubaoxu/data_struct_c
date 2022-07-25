
#include <iostream>
#include <stdio.h>
//#include <string.h>
#include <stdlib.h>

struct Data {
    char cPoint;
    Data* pLeftChild;
    Data* pRightChild;
    Data* pParent;
};

Data* creatTreeNode1 ( char cPoint)
{
    Data* pCurrentNode = (Data*)malloc(sizeof(Data));
    pCurrentNode->pLeftChild = NULL;
    pCurrentNode->pRightChild = NULL;
    pCurrentNode->cPoint = cPoint;
    return pCurrentNode;
}

void creatTreeNode2(Data ** ppCurrentNode)
{
    *ppCurrentNode=(Data*)malloc(sizeof(Data));
    (* ppCurrentNode)->pLeftChild = NULL;
    (* ppCurrentNode)->pRightChild = NULL;
    (* ppCurrentNode)->cPoint = NULL;
    
}

int main()
{
   Data* pFirstNode = creatTreeNode1( 'A');
   Data* pSecondNode = creatTreeNode1('B');
   Data* pThirdNode = creatTreeNode1('C');
   Data* pFourthNode = creatTreeNode1('D');
   Data* pFifthNode = creatTreeNode1('E');
   Data* pSixthNode = creatTreeNode1('F');
   Data* pSeventhNode= creatTreeNode1('G');

    /*pFirstNode->pLeftChild = pSecondNode;
    pSecondNode->pRightChild = pFirstNode;

    pFirstNode->pRightChild = pThirdNode;
    pThirdNode->pParent = pFirstNode;

    pSecondNode->pLeftChild = pFourthNode;
    pFourthNode->pParent = pSecondNode;

    pSecondNode->pRightChild = pFifthNode;
    pFifthNode->pParent = pSecondNode;

    pThirdNode->pRightChild = pSixthNode;
    pSixthNode->pParent = pThirdNode;

    pFifthNode->pRightChild = pSeventhNode;
    pSeventhNode->pParent = pFifthNode;*/

    printf("%c\t%c\t%c\t%c\t%c\t%c\t%c\t", pFirstNode->cPoint, pSecondNode->cPoint, pThirdNode->cPoint, pFourthNode->cPoint, pFifthNode->cPoint, pSixthNode->cPoint, pSeventhNode->cPoint);
    return 0;
}
