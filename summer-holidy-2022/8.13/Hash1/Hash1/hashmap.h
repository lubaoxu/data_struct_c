#pragma once

#include "adt.h"

struct linkNode {
	Data* pData;
	linkNode* pNext;
};

struct HashMap {
	//数组  指针数组 每个数组元素保存着一个单链表的表头
	//保存数组长度
	linkNode* lnArray[10];


};

int hash(HashMap* pHashMap, int nKey);

void insert(HashMap *pHashMap, Data* pData);
void deleteNode(HashMap* pHashMap, int key);

Data* get(HashMap* pHashMap, int key);