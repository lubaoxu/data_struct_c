#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int getParentIndex(int index)
{
	return (index - 1) / 2;
}

void makeHeap(int nArray[], unsigned length)
{
	for (int outerIndex = 1; outerIndex < length; ++outerIndex)
	{
		int innerIndex = outerIndex;
		int parentIndex = getParentIndex(innerIndex);
		while (nArray[innerIndex] > nArray[(innerIndex - 1) / 2])
		{
			int t = nArray[(innerIndex - 1)/2];
			nArray[(innerIndex - 1) / 2] = nArray[innerIndex];
			nArray[innerIndex] = t;
			innerIndex = getParentIndex(innerIndex);
			if (innerIndex == 0)
			{
				break;
			}
		}
	}
}

int main(void)
{
	int nArray[] = { 56,38,26,75,57,22,18,69,92,45 };
	makeHeap(nArray, sizeof(nArray)/ sizeof(nArray[0]));
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", nArray[i]);
	}

	return 0;
}
