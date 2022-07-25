#pragma once
typedef struct People
{
	char name[260];
	int number;
	int age;
	int high;
	People* pNext;
} Peoplestudent;
void readstudent(Peoplestudent* link);	