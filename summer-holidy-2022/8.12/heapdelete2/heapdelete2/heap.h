#pragma once

#include "data.h"

struct Heap {
	Data* m_pArray;  //��Ա����
	int m_nArrayLen;
	int m_nBottom;  //m��ʾmember ��Ա

	void createHeap();  // public  pirvate
	void destroyHeap();   //��Ա����

	void deleteNode();

	void output();

private:
	void swapNode(Data* pTop, Data* pBottom);


};


