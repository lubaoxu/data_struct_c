#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include "Student.h"

Student::Student(int nAge, const char cArray[100])
{
	m_nAge = nAge;
	int length = strlen(cArray) + 1;
	m_pName = (char*) malloc(length);
	memset(m_pName, 0, length);
	strcpy(m_pName, cArray);
	//m_cArray=cArray[100]
}

Student::Student()
{

}

Student::Student(const Student& other)
{
	m_nAge = other.m_nAge;
	std::cout << " ¿½±´¹¹Ôìº¯Êý" << std::endl;
	int length = strlen(other.m_pName) + 1;
	m_pName = (char*)malloc(length);
	memset(m_pName, 0, length);
	strcpy(m_pName, other.m_pName);
}

Student Max(Student m, Student n)
{
	if (m.m_nAge > n.m_nAge)
		return m;
	else
		return n;
}

ostream& operator << (ostream& os, const Student& obj)
{
	os << obj.m_nAge << endl;
	os << obj.m_pName<<endl;
	return os;
}

istream& operator >> (istream& in, Student& obj)
{
	return in;
}