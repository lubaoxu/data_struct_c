#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string.h>

int nRecursion(int n)
{
	if (n == 1)
		return 1;
	else if (n == 2)
		return 2;
	else
		return nRecursion(n - 1) * n;
}

int main()
{
	int nNumber;
	int nSum=0;
	scanf("%d", &nNumber);
	nSum = nRecursion(nNumber);
	printf("%d\n", nSum);
	return 0;

}

