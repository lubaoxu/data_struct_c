// Shell sort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdio.h>
#include <string.h>
void outputData(int a[], int len, int n)
{
	int i, j;
	for (i = n; i < 10; i += n)
	{
		int t = a[i];
		if (t < a[0])
			for (j = i - n; j >= 0; j -= n)
				a[j + n] = a[j];
		else
			for (j = i - n; t< a[j]; j -= n)
				a[j + n] = a[j];
		a[j + n] = t;
	}
}
int main()
{
	int a[10] = { 24,56,64,15,79,85,63,5,70,9 };
	int x = 2;
	int n = 10 / 2;
	while (n)
	{
		int i;
		for(i=0;i<n;++i)
		outputData(&a[i], 9, n);
		if (n < x && n != 1)
		{
			n = 1;
		}
		else
		{
			n = n / 2;
		}
		
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
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
