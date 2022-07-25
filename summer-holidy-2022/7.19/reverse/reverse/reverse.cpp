// reverse.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Data {
    int point;
    Data*pNext;
};
void outputData(Data* Node)
{
    while (Node != NULL)
    {
        printf("%d\n", Node->point);
        Node = Node->pNext;
    }
}

void reverse(Data * pDataHead) {
    printf("reverse link begin\n");
    Data* pPreviousNode = NULL;
    Data* pNextNode = NULL;
    Data* pCurrentNode = pDataHead;
    while (pCurrentNode != NULL)
    {
        // 最后一个节点
        if (pCurrentNode->pNext == NULL)
        {
            pDataHead = pCurrentNode;
            pCurrentNode->pNext = pPreviousNode;
            break;
        }

        int iPrevious = -1;
        if (pPreviousNode != NULL) {
            iPrevious = pPreviousNode->point;
        }
        int iCurrent = -1;
        if (pCurrentNode != NULL) {
            iCurrent = pCurrentNode->point;
        }
        int iNext = -1;
        if (pNextNode != NULL) {
            iNext = pNextNode->point;
        }

        printf("begin\t previous:%d\t current:%d\t next:%d\n", iPrevious, iCurrent, iNext);

        //1：记录下一个节点
        pNextNode = pCurrentNode->pNext;

        //2: 指针反向
        pCurrentNode->pNext = pPreviousNode;

        //3: 记录前一个节点
        pPreviousNode = pCurrentNode;

        // while循环：当前节点指向到下一个节点
        pCurrentNode = pNextNode;

        iPrevious = -1;
        if (pPreviousNode != NULL) {
            iPrevious = pPreviousNode->point;
        }
        iCurrent = -1;
        if (pCurrentNode != NULL) {
            iCurrent = pCurrentNode->point;
        }
        iNext = -1;
        if (pNextNode != NULL) {
            iNext = pNextNode->point;
        }

        printf("end\t previous:%d\t current:%d\t next:%d\n", iPrevious, iCurrent, iNext);

    }  // end while
}

int main()
{
    Data* pDataHead = NULL;
    Data* pTailData = NULL;
    for (int i = 0; i < 10; i++)
    {
        Data* pDataA = (Data*)malloc(sizeof(Data));
        pDataA->point = i+1;
        pDataA->pNext = NULL;
        if (i == 0)
        {
            pDataHead = pDataA;
        }
        else
        {
            pTailData->pNext = pDataA;
        }
        pTailData = pDataA;
    }
    printf("初始化 link begin\n");
    outputData(pDataHead);

    reverse(pDataHead);
    outputData(pDataHead);
 
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
