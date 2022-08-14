#include <stdio.h>

void swapNode(int* pptop, int* ppbottom)
{
	int nTempVal = *pptop;
	*pptop = *ppbottom;
	*ppbottom = nTempVal;
}


void deleteNode(int nArray[], unsigned length)
{
	//swapNode(&top, &bottom);//待总结1
	//swapNode(&(nArray[0]), &(nArray[length - 1])); //待总结2
	swapNode(nArray+0, nArray + (length - 1));
	int outerIndex = 0;
	unsigned nLeftChild = 2 * outerIndex + 1;
	unsigned nRightChild = 2 * outerIndex + 2;
	int nTempVal = nArray[outerIndex];
	while (nLeftChild < length-1 && nTempVal < nArray[nLeftChild] || nRightChild < length-1 && nTempVal < nArray[nRightChild])
	{
		if (nLeftChild < length-1 && nRightChild < length-1)
		{
			if (nArray[nRightChild] < nArray[nLeftChild])
			{
				nArray[outerIndex] = nArray[nLeftChild];
				outerIndex = nLeftChild;
			}
			else
			{
				nArray[outerIndex] = nArray[nRightChild];
				outerIndex = nRightChild;
			}
		}
		else if (nLeftChild < length-1)
		{
			nArray[outerIndex] = nArray[nLeftChild];
			outerIndex = nLeftChild;
		}
		nLeftChild = outerIndex * 2 + 1;
		nRightChild = outerIndex * 2 + 2;
	}
	nArray[outerIndex] = nTempVal;

	
}