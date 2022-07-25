#include <string.h>
#include <iostream>
#include <stdio.h>

void array2(int arr[])
{
		 printf("\n%d\t%d\t%d\n", sizeof(arr[0]), arr[0], arr[1]);
		 printf("%d\t%d\t%d\n", sizeof(*arr), *arr, *(arr + 1));
		printf("sizeof(arr):%d\n", sizeof(arr));
}

void array3(int *pValue,int k,int iCount)
{
	if (k < iCount && k >= 0)
	{
		printf("\n%d\t%d\t%d\n", sizeof(pValue[0]), pValue[0], pValue[1]);
		printf("sizeof:%d\t%d\t%d\n", sizeof(*pValue), *pValue, *(pValue + 1));
		printf("sizeof(pValue):%d\n", sizeof(pValue));
	}
}

int main()
{
	int b[] = {5,6,78,97,45,56,34};
	
	printf("main()  Begin:\n");
	printf("sizeof(arr[0]):%d\n", sizeof(b[0]));
	printf("sizeof(arr):%d\n", sizeof(b));
	array2(b);
	array3(b,5,sizeof(b)/sizeof(b[0]));
  }

