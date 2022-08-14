#pragma once

struct Data {
	int nVal;
	Data(int n) {
		nVal = n;
	}
};

struct Heap {
	Data* pArray;
	int nArrayLen;
	int nBottom;
};

void createHeap(Heap* pHeap);
void destroyHeap(Heap* pHeap);

void deleteNode(Heap* pHeap);

void output(Heap*pHeap);

