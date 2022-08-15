#pragma once
#include "stdio.h"

#include "data.h"

struct linkNode {
	Data* pData;
	linkNode* pNext;
};

struct HashMap {
	//����  ָ������ ÿ������Ԫ�ر�����һ��������ı�ͷ
	//�������鳤��
	linkNode* lnArray[10];


};

int hash(HashMap* pHashMap, int nKey);

void insert(HashMap* pHashMap, Data* pData);

void deleteNode(HashMap* pHashMap, int key);