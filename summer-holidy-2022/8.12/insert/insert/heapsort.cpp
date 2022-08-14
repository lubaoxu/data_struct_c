#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "heapsort.h"

void createHeap(int nArray[], unsigned length)
{
	for (int outerIndex = (length-4) / 2 - 1; outerIndex >= 0; outerIndex--)
	{
		unsigned nLeftChild = 2 * outerIndex + 1;
		unsigned nRightChild = 2 * outerIndex + 2;
		int nTempVal = nArray[outerIndex];
		while (nLeftChild < length && nTempVal < nArray[nLeftChild] || nRightChild < length && nTempVal < nArray[nRightChild])
		{
			if (nLeftChild < length && nRightChild < length)
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
			else if (nLeftChild < length)
			{
				nArray[outerIndex] = nArray[nLeftChild];
				outerIndex = nLeftChild;
			}
			nLeftChild = outerIndex * 2 + 1;
			nRightChild = outerIndex * 2 + 2;
		}
		nArray[outerIndex] = nTempVal;
	}
	
}