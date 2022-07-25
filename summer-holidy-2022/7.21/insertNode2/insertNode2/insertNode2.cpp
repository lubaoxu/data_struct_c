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
        printf("%d\n", pCurrentNode->iPoint);
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

void insertNode(Data* pHead, int nInsert)
{
    Data* pNextNode = NULL;
    Data* pCurrentNode = pHead;
    int i = 1;
    while (pCurrentNode != NULL)
    {
        if (i == nInsert)
        {
            pNextNode = pCurrentNode->pNext;

            Data* pInsertNode = (Data*)malloc(sizeof(Data));
            pInsertNode->iPoint = 100;
            pInsertNode->pNext = NULL;
            pInsertNode->pPrevious = NULL;

            pNextNode->pPrevious = pInsertNode;
            pInsertNode->pNext = pNextNode;
            pCurrentNode->pNext = pInsertNode;
            pInsertNode->pPrevious = pCurrentNode;
            




            break;
        }
        

        pCurrentNode = pCurrentNode->pNext;
        i++;

    }//end while
        
}

int main()
{
    printf("Hello\n");
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
    printf("\n逆序后:\n");
    ReverseOutputData(pTail);
    int Insert = 5;
    insertNode(pHead, Insert);
    printf("\n插入后\n");
    OutputData(pHead);
    printf("\n逆序输出插入\n");
    ReverseOutputData(pTail);
    return 0;
}
