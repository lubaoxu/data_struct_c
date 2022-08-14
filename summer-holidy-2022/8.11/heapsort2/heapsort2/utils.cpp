#include <stdio.h>

#include "heapsort.h"

void output(int nArray[], unsigned length)
{
	int outerIndex;
	for (outerIndex = 0; outerIndex < length; ++outerIndex)
	{
		printf("%d\t", nArray[outerIndex]);
	}
}