#pragma once
#include <iostream>

using namespace std;

class Student
{

public:
	int m_nAge;
	char * m_pName;
	Student(int nAge, const char cArray[100]);
	Student();
	
	Student(const Student& other);
public:
	friend ostream& operator << (ostream& os, const Student& obj);
	friend istream& operator >> (istream& in, Student& obj);
private:
};
Student Max(Student, Student);
