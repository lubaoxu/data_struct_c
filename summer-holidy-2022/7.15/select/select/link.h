#pragma once
typedef struct IntLink
{
	int value;
	IntLink* pNext;
} IntLinkData ;


 struct StudentData//People
{
	char name[260];
	int number;
	int age;
	IntLink* pNext;
} ;//Peoplestudent





void readIntLink(IntLinkData* link);