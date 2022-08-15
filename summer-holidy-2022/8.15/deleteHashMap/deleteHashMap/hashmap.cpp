#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "data.h"
#include "Hashmap.h"

int hash(HashMap* pHashmap, int nKey)
{
	return nKey % (
		sizeof(pHashmap->lnArray) / sizeof(pHashmap->lnArray[0]));
}

void insert(HashMap* pHashMap, Data* pData)
{
	int hashVal = hash(pHashMap, pData->nNumber);

	int index = hashVal;

	if (pHashMap->lnArray[index] == NULL)
	{
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

void deleteNode(HashMap* pHashMap, int key)
{
	int index = hash(pHashMap, key);
	linkNode* pCurrentNode = pHashMap->lnArray[index];
	linkNode* pLastNode = NULL;
	while (pCurrentNode != NULL)
	{
		if (key == pCurrentNode->pData->nNumber)
		{
			if (pCurrentNode->pNext == NULL) 
			{
				if (pCurrentNode->pData->nNumber == pHashMap->lnArray[index]->pData->nNumber)
				{
					free(pHashMap->lnArray[index]);
					pHashMap->lnArray[index] = NULL;
				}
				else 
				{
					free(pLastNode->pNext);
					pLastNode->pNext = NULL;
				}
			}
			else 
			{
				if (pCurrentNode->pData->nNumber == pHashMap->lnArray[index]->pData->nNumber)
				{
					linkNode* pTemp = pCurrentNode;
					pHashMap->lnArray[index] = pCurrentNode->pNext;
					//free(pTemp);
				}
				else {
					linkNode* pTemp = pCurrentNode;
					pLastNode->pNext = pCurrentNode->pNext;
					free(pTemp);
				}
			}
			break;
		}
		pLastNode = pCurrentNode;
		pCurrentNode = pCurrentNode->pNext;
	}
}
