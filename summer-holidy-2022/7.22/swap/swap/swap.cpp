#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <iostream>

struct Data {
    int point;
    Data* pNext;
    Data* pPrevious;
};

void outputData(Data*Head)
{
    Data* pCurrentNode = Head;
    while (pCurrentNode != NULL)
    {
        printf("%d\n", pCurrentNode->point);
        pCurrentNode = pCurrentNode->pNext;
    }
   
}

void ReverseOutputData(Data* Tail)
{
    Data* pCurrentNode = Tail;
    while (pCurrentNode != NULL)
    {
        printf("%d\n", pCurrentNode->point);
        pCurrentNode = pCurrentNode->pPrevious;
    }
}

void SwapData(Data*pHead)
{
    Data* pCurrentNode = pHead;
    Data* pFirstNode = NULL;
    Data* pSecondNode = NULL;
    Data* pThirdNode = NULL;
    Data* pFourthNode = NULL;
    Data* pFifthNode = NULL;
    int i=1;
    while (pCurrentNode != NULL)
    {
        if (i == 1)
        {
            pFirstNode = pCurrentNode;
        }
        else if (i == 2)
        {
            pSecondNode = pCurrentNode;
        }
        else if (i == 3)
        {
            pThirdNode = pCurrentNode;
        }
        else if (i == 4)
        {
            pFourthNode = pCurrentNode;
        }
        else if (i == 5)
        {
            pFifthNode = pCurrentNode;
        }

        pCurrentNode = pCurrentNode->pNext;
     i++;
    }//while End

    pFirstNode->pNext = pFourthNode;
    pFourthNode->pNext = pThirdNode;
    pThirdNode->pPrevious = pFourthNode;
    pFourthNode->pPrevious = pFirstNode;

    pThirdNode->pNext = pSecondNode;
    pSecondNode->pNext = pFifthNode;
    pFifthNode->pPrevious = pSecondNode;
    pSecondNode->pPrevious = pThirdNode;
}

int main()
{
    Data* pHead = NULL;
    Data* pTail = NULL;
    Data* pPreviousNode = NULL;
    Data* pNextNode = NULL;
    for (int i = 1; i <= 10; i++)
    {
        Data* pCurrentNode = (Data*)malloc(sizeof(Data));
        pCurrentNode->point = i;
        pCurrentNode->pPrevious = NULL;
        pCurrentNode->pNext = NULL;
        if (i == 1)
        {
            pHead = pCurrentNode;
        }
        else if (i == 10)
        {
            pTail = pCurrentNode;
        }
        if (i > 1)
        {
            pPreviousNode->pNext = pCurrentNode;
            pCurrentNode->pPrevious = pPreviousNode;
        }
        pPreviousNode = pCurrentNode;
    }//for End
    outputData(pHead);
    printf("逆序输出后\n");
    ReverseOutputData(pTail);
    SwapData(pHead);
    printf("交换后\n");
    outputData(pHead);
    printf("逆序交换后\n");
    ReverseOutputData(pTail);
 }
