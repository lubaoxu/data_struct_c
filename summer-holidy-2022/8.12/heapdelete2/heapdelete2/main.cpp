#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "heap.h"

int main(void)
{
	Heap* pHeap = (Heap*)malloc(sizeof(Heap));

	Data dataArray[] = { Data(56),Data(38),Data(26),Data(75),Data(56),Data(22),Data(18),Data(69),Data(92),Data(95) };

	pHeap->m_pArray = dataArray;
	pHeap->m_nArrayLen = sizeof(dataArray) / sizeof(dataArray[0]);
	pHeap->m_nBottom = pHeap->m_nArrayLen - 1;
	pHeap->createHeap();

	pHeap->deleteNode();

	pHeap->output();

	return 0;
}

