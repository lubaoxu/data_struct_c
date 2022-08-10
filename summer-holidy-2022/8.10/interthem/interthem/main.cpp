#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "data.h"
#include "stack.h"
#include "preorder.h"

int main()
{
	//Data* pFirstNode = NULL;
	createBinaryTpree();
	preorder(pFirstNode);
	//destroyBinaryTree();
	return 0;
}