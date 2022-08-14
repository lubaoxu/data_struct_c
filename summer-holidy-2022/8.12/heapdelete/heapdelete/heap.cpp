#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "heap.h"

void createHeap(Heap* pHeap)
{
	for (int outerIndex = (pHeap->nArrayLen - 2) / 2 - 1; outerIndex >= 0; outerIndex--)
	{
		unsigned nLeftChild = 2 * outerIndex + 1;
		unsigned nRightChild = 2 * outerIndex + 2;
		int nTempVal = pHeap->pArray[outerIndex].nVal;
		while (nLeftChild < pHeap->nArrayLen && nTempVal < pHeap->pArray[nLeftChild].nVal || 
			nRightChild < pHeap->nArrayLen && nTempVal < pHeap->pArray[nRightChild].nVal)
		{
			if (nLeftChild < pHeap->nArrayLen && nRightChild < pHeap->nArrayLen)
			{
				if (pHeap->pArray[nRightChild].nVal < pHeap->pArray[nLeftChild].nVal)
				{
					pHeap->pArray[outerIndex].nVal = pHeap->pArray[nLeftChild].nVal;
					outerIndex = nLeftChild;
				}
				else
				{
					pHeap->pArray[outerIndex].nVal = pHeap->pArray[nRightChild].nVal;
					outerIndex = nRightChild;
				}
			}
			else if (nLeftChild < pHeap->nArrayLen)
			{
				pHeap->pArray[outerIndex].nVal = pHeap->pArray[nLeftChild].nVal;
				outerIndex = nLeftChild;
			}
			nLeftChild = outerIndex * 2 + 1;
			nRightChild = outerIndex * 2 + 2;
		}
		pHeap->pArray[outerIndex].nVal = nTempVal;
	}
	
}

void swapNode(Data* pTop, Data* pBottom)
{
	int nTempVal = pTop->nVal;
	pTop->nVal = pBottom->nVal;
	pBottom->nVal = nTempVal;
}


void deleteNode(Heap* pHeap)
{
	//swapNode(&top, &bottom);//待总结1
	//swapNode(&(nArray[0]), &(nArray[length - 1])); //待总结2
	swapNode(pHeap->pArray + 0, pHeap->pArray + (pHeap->nArrayLen - 1));
	--pHeap->nBottom;

	int outerIndex = 0;
	unsigned nLeftChild = 2 * outerIndex + 1;
	unsigned nRightChild = 2 * outerIndex + 2;
	int nTempVal = pHeap->pArray[outerIndex].nVal;
	while (nLeftChild <= pHeap->nBottom && nTempVal < pHeap->pArray[nLeftChild].nVal ||
		nRightChild <= pHeap->nBottom && nTempVal < pHeap->pArray[nRightChild].nVal)
	{
		if (nLeftChild <= pHeap->nBottom && nRightChild <= pHeap->nBottom)
		{
			if (pHeap->pArray[nRightChild].nVal < pHeap->pArray[nLeftChild].nVal)
			{
				pHeap->pArray[outerIndex] = pHeap->pArray[nLeftChild];
				outerIndex = nLeftChild;
			}
			else
			{
				pHeap->pArray[outerIndex] = pHeap->pArray[nRightChild];
				outerIndex = nRightChild;
			}
		}
		else if (nLeftChild <= pHeap->nBottom)
		{
			pHeap->pArray[outerIndex] = pHeap->pArray[nLeftChild];
			outerIndex = nLeftChild;
		}
		nLeftChild = outerIndex * 2 + 1;
		nRightChild = outerIndex * 2 + 2;
	}
	pHeap->pArray[outerIndex] = nTempVal;

}

void output(Heap* pHeap)
{
	for (int outerIndex = 0; outerIndex <= pHeap->nBottom; outerIndex++)
	{
		printf("%d ", pHeap->pArray[outerIndex].nVal);
	}
}