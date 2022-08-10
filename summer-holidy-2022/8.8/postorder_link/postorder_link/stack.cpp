#include <stdio.h>  // standard input output
#include <stdlib.h>
#include "data.h"
#include "stack.h"

#define MAX_COUNT 100


void initializeStack(Stack* pStack)
{
	pStack->nTop = NULL;
	pStack->Bottom = NULL;
	int nMemSize = MAX_COUNT * sizeof(Data);
	pStack->pDataArray = (Data*)malloc(nMemSize);
	pStack->nCapacity = nMemSize;
}

void pushStack(Stack* pStack, Data* pNode)
{
	(pStack->pDataArray[pStack->nTop]) = *pNode;
	pStack->nTop++;
}

Data* popStack(Stack* pStack)
{
	if (pStack->nTop == NULL)
	{
		return 0;
	}
	pStack->nTop--;
	Data* pData = &(pStack->pDataArray[pStack->nTop]);
	return pData;
}

void unInitializeStack(Stack* pStack)
{
	free(pStack->pDataArray);
	pStack->pDataArray = NULL;
}

