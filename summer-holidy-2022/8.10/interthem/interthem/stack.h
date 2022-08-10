#pragma once
#include "data.h"


typedef struct tagStackData
{
	int nTop;
	int Bottom;
	Data* pDataArray;
	int nCapacity;
}Stack;

void pushStack(Stack* pStack, Data* pNode);
Data* popStack(Stack* pStack);

void initializeStack(Stack* pStack);
void unInitializeStack(Stack* pStack);