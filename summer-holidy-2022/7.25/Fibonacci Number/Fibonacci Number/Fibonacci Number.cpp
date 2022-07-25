#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>



int fibonacciNumber(int n)
{
	if (n == 0)
	{
		return 0;
	}
	 if (n == 1 || n == 2)
	{
		return 1;
	}
	 else
	 {
		 return fibonacciNumber(n - 1) + fibonacciNumber(n - 2);
	 }
}

int main()
{
	int nNumber ;
	int nSum ;
	int n;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d\n", &nNumber);
		nSum = fibonacciNumber(nNumber);
		printf("%d\n", nSum);
	}
	return 0;
}

