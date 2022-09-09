#include <iostream>

#include "constructor.h"


constructor::constructor()
{
	std::cout<<"constructor"<<std::endl;
}

constructor::~constructor()
{
	std::cout << "~constructor" << std::endl;
}

constructor::constructor(const constructor& other)
{
	std::cout << "copy constructor" << std::endl;
}

constructor& constructor::operator=(const constructor& other)
{
	m_dNumber = other.m_dNumber;
	m_dSum = other.m_dSum;
	std::cout << "operator=" << std::endl;
	return *this;
}

constructor* constructor::operator& ()
{
	std::cout << "operator&()" << std::endl;
	return this;
}