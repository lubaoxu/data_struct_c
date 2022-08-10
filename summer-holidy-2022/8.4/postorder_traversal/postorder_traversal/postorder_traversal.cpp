
#include <iostream>
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

void postorder_traversal(Data* pFirstNode)
{
    Stack* pStack = (Stack*)malloc(sizeof(Stack));
    initializeStack(pStack);

    Data* pCurrentNode = pFirstNode;
    int loopCount = 0;
    pCurrentNode->nFlag = 0;
    while (pCurrentNode != NULL)
    {
        printf("第 %d 轮循环 begin %c\n", ++loopCount, pCurrentNode->cPoint);

        if (pCurrentNode->nFlag == 0)
        {
            if (pCurrentNode->pLeftChild != NULL)
            {
                pushStack(pStack, pCurrentNode);
                pCurrentNode = pCurrentNode->pLeftChild;
                pCurrentNode->nFlag = 1;
            }
            else if (pCurrentNode->pRightChild != NULL)
            {
                pushStack(pStack, pCurrentNode);
                pCurrentNode = pCurrentNode->pRightChild;
                pCurrentNode->nFlag = 1;
            }
            else
            {
                printf("%c\n", pCurrentNode->cPoint);
                pCurrentNode->nFlag = 3;
                if (pCurrentNode->pRightChild == NULL)
                {
                    pCurrentNode = popStack(pStack);
                    pCurrentNode->nFlag = 2;
                }
            }
        }
        else if (pCurrentNode->nFlag == 1)
        {
            if (pCurrentNode->pLeftChild != NULL)
            {
                pushStack(pStack, pCurrentNode);
                pCurrentNode = pCurrentNode->pLeftChild;
                pCurrentNode->nFlag = 1;
            }
            else if (pCurrentNode->pRightChild != NULL)
            {
                pushStack(pStack, pCurrentNode);
                pCurrentNode = pCurrentNode->pRightChild;
                pCurrentNode->nFlag = 1;
            }
            else
            {
                printf("%c\n", pCurrentNode->cPoint);
                pCurrentNode->nFlag = 3;
                if (pCurrentNode->pRightChild == NULL)
                {
                    pCurrentNode = popStack(pStack);
                    pCurrentNode->nFlag = 2;
                }
            }
        }
        else if (pCurrentNode->nFlag == 2)
        {
            if (pCurrentNode->pRightChild != NULL)
            {
                pushStack(pStack, pCurrentNode);
                pCurrentNode = pCurrentNode->pRightChild;
                pCurrentNode->nFlag = 2;
            }
            else
            {
                printf("%c\n", pCurrentNode->cPoint);
                pCurrentNode->nFlag = 3;
            }
        }
        else if (pCurrentNode->nFlag == 3)
        {
            pCurrentNode = popStack(pStack);

            if (pCurrentNode != NULL && pCurrentNode->nFlag == 2)
            {
                printf("%c\n", pCurrentNode->cPoint);
                pCurrentNode->nFlag = 3;
            }
            else
            {
                pCurrentNode->nFlag = 2;
                
             
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

void createBinaryTpree(Data** ppFirstNode, Data** ppSecondNode, Data** ppThirdNode,
    Data** ppFourthNode, Data** ppFifthNode, Data** ppSixthNode, Data** ppSeventhNode) {
    *ppFirstNode = creatTreeNode('A');
    *ppSecondNode = creatTreeNode('B');
    *ppThirdNode = creatTreeNode('C');
    *ppFourthNode = creatTreeNode('D');
    *ppFifthNode = creatTreeNode('E');
    *ppSixthNode = creatTreeNode('F');
    *ppSeventhNode = creatTreeNode('G');

    (*ppFirstNode)->pLeftChild = *ppSecondNode;
    (*ppSecondNode)->pParent = *ppFirstNode;

    (*ppFirstNode)->pRightChild = *ppThirdNode;
    (*ppThirdNode)->pParent = *ppFirstNode;

    (*ppSecondNode)->pLeftChild = *ppFourthNode;
    (*ppFourthNode)->pParent = *ppSecondNode;

    (*ppSecondNode)->pRightChild = *ppFifthNode;
    (*ppFifthNode)->pParent = *ppSecondNode;

    (*ppThirdNode)->pRightChild = *ppSixthNode;
    (*ppSixthNode)->pParent = *ppThirdNode;

    (*ppFifthNode)->pRightChild = *ppSeventhNode;
    (*ppSeventhNode)->pParent = *ppFifthNode;
}

void destroyBinaryTree(Data* pFirstNode, Data* pSecondNode, Data* pThirdNode,
    Data* pFourthNode, Data* pFifthNode, Data* pSixthNode, Data* pSeventhNode) {
    free(pFirstNode);
    pFirstNode = NULL;
    free(pSecondNode);
    pSecondNode = NULL;
    free(pThirdNode);
    pThirdNode = NULL;
    free(pFourthNode);
    pFourthNode = NULL;
    free(pFifthNode);
    pFifthNode = NULL;
    free(pSixthNode);
    pSixthNode = NULL;
    free(pSeventhNode);
    pSeventhNode = NULL;
}

int main()
{
    Data* pFirstNode = NULL;
    Data* pSecondNode = NULL;
    Data* pThirdNode = NULL;
    Data* pFourthNode = NULL;
    Data* pFifthNode = NULL;
    Data* pSixthNode = NULL;
    Data* pSeventhNode = NULL;

    createBinaryTpree(&pFirstNode, &pSecondNode, &pThirdNode,
        &pFourthNode, &pFifthNode, &pSixthNode, &pSeventhNode);

    printf("%c\t%c\t%c\t%c\t%c\t%c\t%c\n\n", pFirstNode->cPoint, pSecondNode->cPoint,
        pThirdNode->cPoint, pFourthNode->cPoint, pFifthNode->cPoint,
        pSixthNode->cPoint, pSeventhNode->cPoint);

    postorder_traversal(pFirstNode);
    destroyBinaryTree(pFirstNode, pSecondNode, pThirdNode,
        pFourthNode, pFifthNode, pSixthNode, pSeventhNode);

    return 0;
}


