
#include <iostream>
#include <stdio.h>
//#include <string.h>
#include <stdlib.h>

#define MAX_COUNT 100

struct Data {
    char cPoint;
    Data* pLeftChild;
    Data* pRightChild;
    Data* pParent;
    int flag;// 0:未访问  1：已访问未输出  2：已输出
};

typedef struct tagStackData
{
    int nTop;
    int nBottom;
    Data* pDataArray;
    int nCapacity;
}Stack;

Data* creatTreeNode1(char cPoint)
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
    pStack->nBottom = NULL;
    int nMemSize = MAX_COUNT * sizeof(Data);
    pStack->pDataArray = (Data*)malloc(nMemSize);
    memset(pStack->pDataArray, 0, nMemSize);
    pStack->nCapacity = nMemSize;
}

void pushStack(Stack* pStack, Data*pNode)
{
    pStack->pDataArray[pStack->nTop] = *pNode;
    pStack->nTop++;
}

Data* popStack(Stack* pStack)
{
    if (pStack->nTop == 0) {
        return NULL;
    }
    pStack->nTop--;
    Data* data = &(pStack->pDataArray[pStack->nTop]);
    return data;
}

void unInitializeStack(Stack* pStack) {
    free(pStack->pDataArray);
    pStack->pDataArray = NULL;
}

void preOrder(Data* pFirstNode)
{
    Stack* pStack = (Stack*)malloc(sizeof(Stack));
    initializeStack(pStack);

    Data* pCurrentNode = pFirstNode;
    while (pCurrentNode != NULL)
    {
        printf("%c\n", pCurrentNode->cPoint);
        if (pCurrentNode->pRightChild != NULL)
        {
            pushStack(pStack, pCurrentNode->pRightChild);
        }
        if (pCurrentNode->pLeftChild != NULL)
        {
            pCurrentNode = pCurrentNode->pLeftChild;
        }
        else 
        {
            pCurrentNode = popStack(pStack);
        }
    }
    

    unInitializeStack(pStack);
    free(pStack);


}



int main()
{
    Data* pFirstNode = creatTreeNode1('A');
    Data* pSecondNode = creatTreeNode1('B');
    Data* pThirdNode = creatTreeNode1('C');
    Data* pFourthNode = creatTreeNode1('D');
    Data* pFifthNode = creatTreeNode1('E');
    Data* pSixthNode = creatTreeNode1('F');
    Data* pSeventhNode = creatTreeNode1('G');

    pFirstNode->pLeftChild = pSecondNode;
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
    pSeventhNode->pParent = pFifthNode;

    printf("%c\t%c\t%c\t%c\t%c\t%c\t%c\n\n", pFirstNode->cPoint, pSecondNode->cPoint, pThirdNode->cPoint, pFourthNode->cPoint, pFifthNode->cPoint, pSixthNode->cPoint, pSeventhNode->cPoint);
    
     preOrder(pFirstNode);

    return 0;
}


