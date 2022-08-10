#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "data.h"

void preorder(Data* pFirstNode)
{
	Data* pCurrentNode = pFirstNode;
	if (pCurrentNode == NULL)
	{
		return;
	}
	printf("%c\n", pCurrentNode->cPoint);
	preorder(pCurrentNode->pLeftChild);
	preorder(pCurrentNode->pRightChild);
}