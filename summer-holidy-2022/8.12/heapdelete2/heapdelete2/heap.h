#pragma once

#include "data.h"

struct Heap {
	Data* m_pArray;  //成员变量
	int m_nArrayLen;
	int m_nBottom;  //m表示member 成员

	void createHeap();  // public  pirvate
	void destroyHeap();   //成员函数

	void deleteNode();

	void output();

private:
	void swapNode(Data* pTop, Data* pBottom);


};


