#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include "bookstore.h"

BookStore::BookStore(int nNumber, const char cName[])
{
	m_nNumber = nNumber;
	memset(m_cName, 0, sizeof(m_cName));
	strcpy(m_cName, cName);

	std::cout << "双参数构造函数" << std::endl;
}

BookStore::BookStore()
{

}

BookStore::BookStore(const BookStore& other)
{
	m_nNumber = other.m_nNumber;
	strcpy(m_cName, other.m_cName);
	std::cout << " 拷贝构造函数" << std::endl;
}

BookStore  Max(BookStore m,BookStore n)
{
	if (m.m_nNumber > n.m_nNumber)
		return m;
	else
		return n;
}

BookStore& MaxR(BookStore& A, BookStore& B)
{
	if (A.m_nNumber > B.m_nNumber)
		return A;
	else
		return B;

}

BookStore  MaxR1(BookStore& A, BookStore& B)
{
	if (A.m_nNumber > B.m_nNumber)
		return A;
	else
		return B;
}

BookStore& MaxR2(BookStore A, BookStore B)
{
	if (A.m_nNumber > B.m_nNumber)
		return A;
	else
		return B;

}

const BookStore& MaxRC(const BookStore& A, const BookStore& B)
{
	if (A.m_nNumber > B.m_nNumber)
		return A;
	else
		return B;

}

