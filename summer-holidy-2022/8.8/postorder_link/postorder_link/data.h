#pragma once

struct Data {
	char cPoint;
	Data* pLeftChild;
	Data* pRightChild;
	Data* pParent;
	int nFlag;
};

typedef struct tagStackData
{
	int nTop;
	int Bottom;
	Data* pDataArray;
	int nCapacity;
}Stack;



int g_i = 10;