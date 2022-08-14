#pragma once

#include "data.h"

#define  MAX_COUNT 100

struct Stack
{
	int nTop;
	int Bottom;
	Data* pDataArray;
	int nCapacity;


	void initializeStack();
	void unInitializeStack();
	void pushStack(Data* pNode);
	Data* popStack();
};

