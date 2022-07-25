// Shell sort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdio.h>
#include <string.h>
void sort(int a[], unsigned len, unsigned x)
{
	unsigned i;
	int	j;
	for (i = x; i < len; i+=x)
	{
		int t = a[i];
		if (t < a[0])
		{
			for (j = i - x; j >= 0; j-=x)
			{
				a[j + x] = a[j];
			}
		}
		else
		{
			for (j = i - x; a[j] > t; j-=x)
			{
				a[j + x] = a[j];
			}
		}
		a[j + x] = t;
	}
}
int main()
{
	int a[10] = { 24,56,64,15,79,85,63,5,70,9 };
	unsigned n=2;
	unsigned x = 10 / n;
	while (x)
	{
		unsigned i;
		for (i = 0; i < x; ++i)
		{
			sort(&a[i], 10-i, x);
		}
		if (x < 2 && x != 1)
			x = 1;
		else
			x /= n;
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
