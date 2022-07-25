// reverse.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct reverseData {
    int point;
    reverseData* pNext;
};
void outputreverse(reverseData* Node)
{
    while (Node != NULL)
    {
        printf("%d %x\n", Node->point, Node->point);
        Node = Node->pNext;
    }
}
void outputreverse1(reverseData* Node)
{
    while (Node != NULL)
    {
        printf("%d %x\n", Node->point, Node->point);
        Node->pNext = Node;
    }
}

int main()
{
    reverseData* reverseHead = NULL;
    reverseData* reverseEnd = NULL;
    for (int i = 0; i < 10; i++)
    {
        reverseData* reverseDataA = (reverseData*)malloc(sizeof(reverseData));
        reverseDataA->point = i;
        reverseDataA->pNext = NULL;
        if (i == 0)
        {
            reverseHead = reverseDataA;
        }
        else
        {
            reverseEnd->pNext = reverseDataA;
        }
        reverseEnd = reverseDataA;
    }
    outputreverse(reverseHead);

    reverseData* pFirstNode = NULL;
    reverseData* pThirdNode = NULL;
    reverseData* pFifthNode = NULL;
    reverseData* pSeventhNode = NULL;
    reverseData* pEighthNode = NULL;
    reverseData* pNinthNode = NULL;
    reverseData* pTenthNode = NULL;
    reverseData* current = reverseHead;
    int i = 1;
    while (current)
    {
        if (i == 1)
            pFirstNode = current;
        else if (i == 3)
            pThirdNode = current;
        else if (i == 5)
            pFifthNode = current;
        else if (i == 7)
            pSeventhNode = current;
        else if (i == 8)
            pEighthNode = current;
        else if (i == 9)
            pNinthNode = current;
        else if (i == 10)
        {
            pTenthNode = current;
            break;
        }
        current->pNext = current;
        //current = current->pNext;
        i++;
    }
    pTenthNode = pNinthNode->pNext;
    pNinthNode->pNext = pEighthNode;
    pEighthNode->pNext = pSeventhNode;
    pSeventhNode->pNext = pSeventhNode;
    pSeventhNode->pNext = pFifthNode->pNext;
    pFifthNode->pNext = pFifthNode;
    pFifthNode->pNext = pThirdNode->pNext;
    pThirdNode->pNext = pThirdNode;
    pThirdNode->pNext = pFirstNode->pNext;
    pFirstNode->pNext = pFirstNode;
    pFirstNode->pNext = NULL;
    outputreverse1(reverseHead);
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
