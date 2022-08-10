#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "data.h"
#include "stack.h"

void initializeStack(Stack* pStack)
{
	pStack->nTop = NULL;
	pStack->Bottom = NULL;
	pStack->pDataArray = (Data*)malloc(sizeof(Data) * 100);
	pStack->nCapacity = 100;
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
	Data* data = &(pStack->pDataArray[pStack->nTop]);
	return data;
}

void unInitializeStack(Stack* pStack)
{
	free(pStack->pDataArray);
	pStack->pDataArray = NULL;
}