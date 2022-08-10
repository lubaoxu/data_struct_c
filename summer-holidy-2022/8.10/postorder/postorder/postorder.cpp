#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "data.h"

void postorder(Data* pFirstNode)
{
	Data* pCurrentNode = pFirstNode;
	if (pCurrentNode == NULL)
	{
		return;
	}
	postorder(pCurrentNode->pLeftChild);
	postorder(pCurrentNode->pRightChild);
	printf("%c\n", pCurrentNode->cPoint);
}