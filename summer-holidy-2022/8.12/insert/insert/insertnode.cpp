#include "insertnode.h"

void insertNode(int nArray[], unsigned length)
{
	int outerIndex = length / 2 - 1;
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