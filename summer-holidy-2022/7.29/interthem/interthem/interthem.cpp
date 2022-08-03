
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
    int nFlag;
};

typedef struct tagStackData
{
    int nTop;
    int nBottom;
    Data* pDataArray;
    int nCapacity;
}Stack;

Data* creatTreeNode(char cPoint)
{
    Data* pNode = (Data*)malloc(sizeof(Data));
    pNode->pLeftChild = NULL;
    pNode->pRightChild = NULL;
    pNode->nFlag = 0;
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

void unInitializeStack(Stack* pStack) {
    free(pStack->pDataArray);
    pStack->pDataArray = NULL;
}

void preOrder(Data* pFirstNode)
{
    Stack* pStack = (Stack*)malloc(sizeof(Stack));
    initializeStack(pStack);

    Data* pCurrentNode = pFirstNode;
    int loopCount = 0;
    while (pCurrentNode != NULL)
    {
        printf("第 %d 轮循环 begin %c\n", ++loopCount, pCurrentNode->cPoint);
        if (pCurrentNode->pLeftChild != NULL)
        {
            if (pCurrentNode->nFlag == 0) {
                pushStack(pStack, pCurrentNode);
                pCurrentNode->nFlag = 1;
                pCurrentNode = pCurrentNode->pLeftChild;
            }
            if (pCurrentNode->nFlag == 1)
            {
                printf("%c\n", pCurrentNode->cPoint);
                pCurrentNode->nFlag = 2;
                if (pCurrentNode->pRightChild != NULL)
                {
                    pCurrentNode = pCurrentNode->pRightChild;
                }
                else
                {
                    pCurrentNode = popStack(pStack);
                    pCurrentNode->nFlag = 1;
                }
            }
            if (pCurrentNode->nFlag == 2)
            {
                if (pCurrentNode->pRightChild != NULL)
                {
                    pCurrentNode = pCurrentNode->pRightChild;
                }
            }
        }
        else
        {
            printf(" %c\n", pCurrentNode->cPoint);
            pCurrentNode->nFlag = 2;
            if (pCurrentNode->pRightChild != NULL)
            {
                pCurrentNode = pCurrentNode->pRightChild;
            }
            else
            {
                pCurrentNode = popStack(pStack);
                if (pCurrentNode != NULL) {
                    printf(" %c\n", pCurrentNode->cPoint);
                    pCurrentNode->nFlag = 2;
                }
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
    unInitializeStack(pStack);
    free(pStack);

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


