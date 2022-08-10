
#pragma once
struct Data {
	char cPoint;
	Data* pLeftChild;
	Data* pRightChild;
	Data* pParent;
};
Data* creatTreeNode(char cPoint);
void createBinaryTpree();
void destroyBinaryTree();