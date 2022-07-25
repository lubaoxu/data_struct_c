#pragma once
#include <stdio.h>

int main(void)
{
	int a[10] = { 1,5,9,7,3,2,4,8,6,0 };//定义十个数字
	int i, j, t;
	{
		for (i = 0; i < 9; i++)//通过循环遍历每一个数，
		{
			for (j = 0; j < 9 - i; j++)//9-i:每一次循环结束最后一个元素为最大值。之后无需遍历此位置的元素。
			{
				if (a[j] > a[j + 1])//通过比较相邻元素，进行改变位置
				{
					t = a[j];
					a[j] = a[j + 1];
					a[j + 1] = t;
				}
			}
		 }
	}
	for (i = 0; i < 10; i++)//通过循环输出结果值。
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}

