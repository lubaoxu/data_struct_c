#pragma once
//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Student{
	int stu_id;
	char stu_name[20];
	char stu_class[20];
	int stu_c;
}STU;

void printInfo(STU* p, int n);

void inputInfo()
{
	STU stuinfo[10];
	int n;
	//scanf("%d",&n);
	int i;
	for (i = 0; i < 4; i++)
	{
		scanf("%d%s%s%d", &stuinfo[i].stu_id, &stuinfo[i].stu_name, &stuinfo[i].stu_class, &stuinfo[i].stu_c);

	}
	printInfo(stuinfo, 4);
}
void printInfo(STU* p, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d %d %d %d\n", p[i].stu_id, p[i].stu_name, p[i].stu_class, p[i].stu_c);
	}
}
int main()
{
	inputInfo();
	return 0;
}

