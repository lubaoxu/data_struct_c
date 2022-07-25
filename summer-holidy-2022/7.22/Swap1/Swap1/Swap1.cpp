#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <iostream>

struct Data {
    int point;
    Data* pNext;
    Data* pPrevious;
};

void outputData(Data* Head)
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

void SwapData(Data* pHead,int nSwap1,int nSwap2)
{
    Data* pCurrentNode = pHead;
    Data* pSwap1PreviousNode = NULL;
    Data* pSwap2NextNode = NULL;
    Data* pSwap1Node = NULL;
    Data* pSwap2PreviousNode = NULL;
    Data* pSwap2Node = NULL;
    int i = 1;
    while (pCurrentNode != NULL)
    {
        if (i == nSwap1 - 1)
        {
            pSwap1PreviousNode = pCurrentNode;
        }
        if (i == nSwap1)
        {
            pSwap1Node = pCurrentNode;
        }
        if (i == nSwap2 - 1)
        {
            pSwap2PreviousNode = pCurrentNode;
        }
        if (i == nSwap2)
        {
            pSwap2Node = pCurrentNode;
        }
        if (i == nSwap2 + 1)
        {
            pSwap2NextNode = pCurrentNode;
        }

        pCurrentNode = pCurrentNode->pNext;
        i++;
    }//while End;
    
    pSwap2Node->pNext = pSwap1Node->pNext;
    pSwap1PreviousNode->pNext = pSwap2Node;
    pSwap2Node->pPrevious = pSwap1PreviousNode;
    pSwap2Node->pNext->pPrevious = pSwap2Node;

    pSwap1Node->pNext = pSwap2NextNode;
    pSwap2PreviousNode->pNext = pSwap1Node;
    pSwap1Node->pPrevious = pSwap2PreviousNode;
    pSwap2NextNode->pPrevious = pSwap1Node;
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
    int a = 5;
    int b = 8;
    SwapData(pHead,a,b);
    printf("交换后\n");
    outputData(pHead);
    printf("逆序交换后\n");
    ReverseOutputData(pTail);
}
