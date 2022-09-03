#include <iostream>

#include "bookstore.h"

int main()
{
	BookStore shopA(70, "adsf");
	BookStore shopB(346, "sadfjkl");

	 BookStore  result = 	Max(shopA, shopB);
	std::cout << "max " << result.m_nNumber << std::endl;
	std::cout << "max " << result.m_cName << std::endl;

	return 0;
}