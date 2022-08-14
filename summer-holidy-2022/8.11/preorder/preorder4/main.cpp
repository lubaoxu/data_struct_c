#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "data.h"
#include "stack.h"
#include "preorder.h"
#include "binarytree.h"

int main()
{
	Data* pFirstNode = createBinaryTpree();
	preorder(pFirstNode);
	destroyBinaryTree();
	return 0;
}