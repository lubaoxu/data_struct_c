﻿// insert.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
void insert(char a[], int len)
{
    unsigned i;
    int j;
    for (i = 0; i < len; ++i)//通过循环遍历每一个元素
    {
        char t = a[i];//存放遍历时第i个元素的值
        if (t < a[0])//判断是否小于第一个元素
        {
            for (j = i - 1; j >= 0; --j)//找到头节点
            {
                a[j + 1] = a[j];//将元素插入，所有元素所在空间向后移一个空间；
            }
        }
        else
            for (j = i - 1; t < a[j]; --j)//逐一遍历寻找插入元素中首个比t大的元素
            {
                a[j + 1] = a[j];//此元素后每个元素所在空间向后平移一个空间：
               
            }
        a[j + 1] = t;//最后将腾出来的空间赋值为当时a[i]的值
    }
    for (i = 0; i < len; i++)//通过循环输出
    {
        printf("%d ", a[i]);
    }
}
int main()
{
    char a[10] = { 30,20,50,35,40,60,95,85,90,10 };
    insert(a, 10);
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
