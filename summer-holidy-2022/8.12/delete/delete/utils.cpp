#include <stdio.h>

#include "utils.h"

void output(int nArray[], unsigned length)
{
	for (int outerIndex = 0; outerIndex < length-1; outerIndex++)
	{
		printf("%d ", nArray[outerIndex]);
	}
}