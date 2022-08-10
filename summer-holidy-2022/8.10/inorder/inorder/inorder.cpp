#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "data.h"

void inorder(Data* pFirstNode)
{
	Data* pCurrentNode = pFirstNode;
	if (pCurrentNode == NULL)
	{
		return;
	}
	inorder(pCurrentNode->pLeftChild);
	printf("%c\n", pCurrentNode->cPoint);
	inorder(pCurrentNode->pRightChild);
}