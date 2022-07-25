#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

struct Data {
    int iPoint;
    Data* pNext;
    Data* pPrevious;
};

void OutputData(Data* pHead)
{
    Data* pCurrentNode = pHead;
    while (pCurrentNode != NULL)
    {
        printf("%d\n",pCurrentNode->iPoint);
        pCurrentNode = pCurrentNode->pNext;
    }
}
void ReverseOutputData(Data* pTail)
{
    Data* pCurrentNode = pTail;
    while (pCurrentNode != NULL)
    {
        printf("%d\n", pCurrentNode->iPoint);
        pCurrentNode = pCurrentNode->pPrevious;
    }
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
        pCurrentNode->pNext = NULL;
        pCurrentNode->pPrevious = NULL;
        pCurrentNode->iPoint = i;
      
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

    }
    OutputData(pHead);
    printf("逆序后:\n");
    ReverseOutputData(pTail);
    return 0;
}
