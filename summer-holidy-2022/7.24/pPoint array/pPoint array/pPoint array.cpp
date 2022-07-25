#include <string.h>
#include <stdio.h>
#include <iostream>
#include  <stdlib.h>

int pointer_array()
{
	const char* names = {
		"zara Ali"
		"Hina Ali"
		"Nuhb Ali"
		"Sara Ali"
	};
	int i = 0;
	printf("names addr=%p\n", names);
	for (i = 0; i < 4; i++)
	{
		printf("Value of names[%d]=%s addr=%p \n", i, names[i], (names + i));
	}
	return 0;
}

int main()
{
	int a = 1;
	int b = 2;
	int* p[2];
	p[0] = &a;
	p[1] = &b;
	printf("%p\n", p[0]);
	printf("%p\n", &a);
	printf("%p\n", p[1]);
	printf("%p\n", &b);
	printf("%d\n", *p[0]);
	printf("%d\n", *p[1]);
	//将二维数组赋值给指针数组
	int* pp[3];
	int c[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
	for (int i = 0; i < 3; i++)
	{
		pp[i] = c[i];
	}
	for (int i = 0; i < 3; i++)
	{
		printf("%d\n", pp[i]);
	}

}
