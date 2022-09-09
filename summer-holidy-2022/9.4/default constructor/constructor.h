#pragma once		

// C++五大默认成员函数

class constructor
{
private:
	double m_dNumber;
	double m_dSum;
public:
	constructor();		//1.默认构造函数
	~constructor();		//2.默认析构函数
	constructor(const constructor& other);	//3.默认拷贝构造函数
	constructor& operator=(const constructor& other);	//4.默认赋值操作符函数
	constructor* operator&();	//5.默认取地址操作符函数

};

