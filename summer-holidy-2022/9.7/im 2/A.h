#pragma once

#include <iostream>

/**
	虚函数表指针 __vfptr  指向virtual虚拟函数数组

*/

class A
{
public:
	void fun()
	{
		std::cout << "A:fun()" << std::endl;
		
	}
	virtual void gun()
	{
		std::cout << "A:gun()" << std::endl;
	}
};

class B : public A
{
public:
    int fun()
	{
		std::cout << "B:fun()" << std::endl;
		return 1;
	}
	void gun()
	{
		std::cout << "B:gun()" << std::endl;
	}
};


