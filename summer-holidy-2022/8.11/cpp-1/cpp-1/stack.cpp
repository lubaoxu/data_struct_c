#include <stdlib.h>
#include <iostream>
#include "stack.h"

void Stack::initializeStack()
{
	nTop = NULL;
	Bottom = NULL;
	int nMemSize = MAX_COUNT * sizeof(Data);
	pDataArray = (Data*)malloc(nMemSize);
	nCapacity = nMemSize;
}

void Stack::unInitializeStack() {
}

void Stack::pushStack(Data* pNode)
{
	(pDataArray[nTop]) = *pNode;
	nTop++;
}

Data* Stack::popStack()
{
	if (nTop == NULL)
	{
		return 0;
	}
	nTop--;
	Data* data = &(pDataArray[nTop]);
	return data;
}

