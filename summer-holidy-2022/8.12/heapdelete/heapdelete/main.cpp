#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "heap.h"

int main(void)
{
	Heap* pHeap = (Heap*)malloc(sizeof(Heap));

	Data dataArray[] = { Data(56),Data(38),Data(26),Data(75),Data(56),Data(22),Data(18),Data(69),Data(92),Data(95)};

	pHeap->pArray = dataArray;
	pHeap->nArrayLen = sizeof(dataArray) / sizeof(dataArray[0]);
	pHeap->nBottom = pHeap->nArrayLen - 1;
	createHeap(pHeap);

	deleteNode(pHeap);
	
	output(pHeap); 
	
	return 0;
}

