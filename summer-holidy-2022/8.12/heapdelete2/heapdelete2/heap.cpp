#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "heap.h"

void Heap::createHeap()
{
	for (int outerIndex = (m_nArrayLen - 2) / 2 - 1; outerIndex >= 0; outerIndex--)
	{
		unsigned nLeftChild = 2 * outerIndex + 1;
		unsigned nRightChild = 2 * outerIndex + 2;
		int nTempVal = m_pArray[outerIndex].nVal;
		while (nLeftChild < m_nArrayLen && nTempVal < m_pArray[nLeftChild].nVal ||
			nRightChild < m_nArrayLen && nTempVal < m_pArray[nRightChild].nVal)
		{
			if (nLeftChild < m_nArrayLen && nRightChild < m_nArrayLen)
			{
				if (m_pArray[nRightChild].nVal < m_pArray[nLeftChild].nVal)
				{
					m_pArray[outerIndex].nVal = m_pArray[nLeftChild].nVal;
					outerIndex = nLeftChild;
				}
				else
				{
					m_pArray[outerIndex].nVal = m_pArray[nRightChild].nVal;
					outerIndex = nRightChild;
				}
			}
			else if (nLeftChild < m_nArrayLen)
			{
				m_pArray[outerIndex].nVal = m_pArray[nLeftChild].nVal;
				outerIndex = nLeftChild;
			}
			nLeftChild = outerIndex * 2 + 1;
			nRightChild = outerIndex * 2 + 2;
		}
		m_pArray[outerIndex].nVal = nTempVal;
	}

}

void Heap::swapNode(Data* pTop, Data* pBottom)
{
	int nTempVal = pTop->nVal;
	pTop->nVal = pBottom->nVal;
	pBottom->nVal = nTempVal;
}

void Heap::deleteNode()
{
	
	//swapNode(&top, &bottom);//待总结1
	//swapNode(&(nArray[0]), &(nArray[length - 1])); //待总结2
	swapNode(m_pArray + 0, this->m_pArray + (m_nArrayLen - 1));
	--m_nBottom;

	int outerIndex = 0;
	unsigned nLeftChild = 2 * outerIndex + 1;
	unsigned nRightChild = 2 * outerIndex + 2;
	int nTempVal = m_pArray[outerIndex].nVal;
	while (nLeftChild <= m_nBottom && nTempVal < m_pArray[nLeftChild].nVal ||
		nRightChild <= m_nBottom && nTempVal < m_pArray[nRightChild].nVal)
	{
		if (nLeftChild <= m_nBottom && nRightChild <= m_nBottom)
		{
			if (m_pArray[nRightChild].nVal < m_pArray[nLeftChild].nVal)
			{
				m_pArray[outerIndex] = m_pArray[nLeftChild];
				outerIndex = nLeftChild;
			}
			else
			{
				m_pArray[outerIndex] = m_pArray[nRightChild];
				outerIndex = nRightChild;
			}
		}
		else if (nLeftChild <= m_nBottom)
		{
			m_pArray[outerIndex] = m_pArray[nLeftChild];
			outerIndex = nLeftChild;
		}
		nLeftChild = outerIndex * 2 + 1;
		nRightChild = outerIndex * 2 + 2;
	}
	m_pArray[outerIndex] = nTempVal;

}

void Heap::output()
{
	for (int outerIndex = 0; outerIndex <= m_nBottom; outerIndex++)
	{
		printf("%d ", m_pArray[outerIndex].nVal);
	}
}