#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "adt.h"
#include "hashmap.h"

int hash(HashMap* pHashMap, int nKey)
{
	return nKey % (
		sizeof(pHashMap->lnArray) / sizeof(pHashMap->lnArray[0])
		);
}

void insert(HashMap *pHashMap, Data* pData)
{
	int hashVal = hash(pHashMap, pData->nNumber);

	int index = hashVal;

	if (pHashMap->lnArray[index] == NULL) {
		linkNode* pHeadNode = (linkNode*)malloc(sizeof(linkNode));
		pHeadNode->pData = pData;
		pHeadNode->pNext = NULL;
		pHashMap->lnArray[index] = pHeadNode;
		return;
	}

	linkNode* pHeadNode = pHashMap->lnArray[index];
	linkNode* pLastNode = pHeadNode;
	linkNode* pCurrentNode = pHeadNode;
	while (pCurrentNode != NULL)
	{
		pLastNode = pCurrentNode;
		pCurrentNode = pCurrentNode->pNext;
	}

	linkNode* pTempNode = (linkNode*)malloc(sizeof(linkNode));
	pTempNode->pData = pData;
	pTempNode->pNext = NULL;
	pLastNode->pNext = pTempNode;
}

Data* get(HashMap* pHashMap, int key)
{
	int index = hash(pHashMap, key);
	linkNode* pCurNode = pHashMap->lnArray[index];
	
	while (pCurNode!=NULL)
	{
		if (key == pCurNode->pData->nNumber) {
			return pCurNode->pData;
		}
		pCurNode = pCurNode->pNext;
	}

	return NULL;
}

void deleteNode(HashMap* pHashMap, int key)
{

}

