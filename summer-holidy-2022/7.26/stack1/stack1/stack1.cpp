#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

#define MAX_COUNT 100

// hello

struct tagData {
	int nPrice;
	int weight;
};
typedef tagData Data;

struct tagStackData {
	int nTop;
	int nBottom;
	Data* pDataArray; // *pDataArray  pDataArray[0]
	int nCapacity;
};
typedef tagStackData Stack;

void initializeStack(Stack* pStack)
{
	pStack->nBottom = 0;
	pStack->nTop = 0;
	int nMemSize = MAX_COUNT * sizeof(Data);
	pStack->pDataArray = (Data*)malloc(nMemSize);
	memset(pStack->pDataArray, 0, nMemSize);
	pStack->nCapacity = MAX_COUNT;
}

void unInitializeStack(Stack* pStack) {
	free(pStack->pDataArray);
}

void pushStack(Stack* pStack, int nVal)
{
	Data data = pStack->pDataArray[pStack->nTop];
	data.nPrice = nVal;

	pStack->pDataArray[pStack->nTop].nPrice = nVal;

	pStack->nTop++;
}

Data popStack(Stack* pStack) {
	pStack->nTop--;
	Data data = pStack->pDataArray[pStack->nTop];
	return data;
}

void nMultiply(int nVal) {
	// 1: 初始化 stack
	Stack* pStack = (Stack*)malloc(sizeof(Stack));
	initializeStack(pStack);

	// 2: 压栈
	int array[1000] = { };
	int nTemp = nVal;
	while (nTemp >= 1)
	{
		pushStack(pStack, nTemp--);
	}

	int nResult = 1;

	// 3: 出栈
	while (true)
	{
		Data data = popStack(pStack);
		nResult = nResult * data.nPrice;
		if (pStack->nTop == 0) {
			break;
		}
	}

	printf("n:%d\tresult:%d\n", nVal, nResult);

	// 5: 栈空间释放。
	unInitializeStack(pStack);
	free(pStack);
}

int main()
{
	nMultiply(3);
	nMultiply(4);
	nMultiply(5);
	nMultiply(6);
	nMultiply(7);
	nMultiply(8);
	nMultiply(9);
	nMultiply(10);
	nMultiply(30);
	return 0;
}



