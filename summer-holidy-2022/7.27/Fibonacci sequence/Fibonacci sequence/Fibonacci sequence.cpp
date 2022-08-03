#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

#define MAX_COUNT 100


typedef struct tagData{
int npoint;
}Data;

typedef struct tagStackData
{
	int nTop;
	int nBottom;
	Data* pDataArray;
	int nCapacity;
}Stack;

void initializeStack(Stack* pStack)
{
	pStack->nTop = NULL;
	pStack->nBottom = NULL;
	int nMemSize = MAX_COUNT * sizeof(Data);
	pStack->pDataArray = (Data*)malloc(nMemSize);
	pStack->nCapacity = nMemSize;

}

void pushStack(Stack* pStack, int nVal)
{
	Data data = pStack->pDataArray[pStack->nTop];
	
	Data * pData1 = &(pStack->pDataArray[pStack->nTop])  ;
	Data* pData2 = pStack->pDataArray + pStack->nTop;


	//int array1[10] = { 0 };
	//int x = array1[0];
	//x = 10;

	//int* pX = &(array1[6]);
	//int* pX = array1+6;
	//*pX = 10;

	//.npoint = nVal;
	
	pData1->npoint = nVal;
	
	pStack->nTop++;

}

void unInitializeStack(Stack* pStack) {
	free(pStack->pDataArray);
	pStack->pDataArray = NULL;
}

Data popStack(Stack* pStack)
{
	pStack->nTop--;
	Data data = pStack->pDataArray[pStack->nTop];
	return data;
}

void nFibonacci(int nVal)
{
	Stack* pStack = (Stack*)malloc(sizeof(Stack*));
	initializeStack(pStack);

	int array[100] = { };
	int nTemp = nVal;
	while (nTemp>=0)
	{
		pushStack(pStack, nTemp--);
	}

	int nResult = popStack(pStack).npoint;

	while (true)
	{
		Data data = popStack(pStack);
	
		nResult += data.npoint;


		if (pStack->nTop == 0) {
			break;
		}
	}
	printf("n:%d\tresult:%d\n", nVal, nResult);

	unInitializeStack(pStack);
	free(pStack);

}

int main()
{
	nFibonacci(1);
	nFibonacci(2);
	nFibonacci(3);
	nFibonacci(4);
	nFibonacci(5);
}

