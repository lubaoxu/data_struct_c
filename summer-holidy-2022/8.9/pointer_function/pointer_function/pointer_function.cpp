#include <stdio.h>
#include <string.h>

// 问题：函数指针和指针函数区别？  对比  数组指针VS指针数组

// part 1
int getX()
{
	int x = 100;
	return x;
}

// part 2
void output() {
	printf("hello i am output\n");
}

// part 3
void outputWithPara(int i, float f, double d, char ch) {
	printf("hello i am output %d   %f  %lf  %c \n", i, f, d ,ch);
}

// part 4
float getFloatVal(int i) {
	float f = i * 100;
	return f;
}
// 指针函数： 返回值是一个指针的函数。
int* getPointer() {
	int ii = 800;
	return &ii;
}

int main()
{
	// part 1
	int (*p)() = getX;
	int (*p1)() = &getX;
	int j = (*p)();
	printf("%d\n", j);

	// part 2
	void (*pOutput)() = output;
	pOutput();
	(*pOutput)();

	// part 3  parameter 参数
	void (*pOutputWithPara)(int, float, double, char) = outputWithPara;
	pOutputWithPara(4,5, 6, 'A');
	(* pOutputWithPara)(4, 5, 6, 'A');

	// part 4 
	float (*pGetFloatVal)(int) = &getFloatVal;
	float f1 = pGetFloatVal(2);
	printf("%f\n", f1);
	float f2 = ( * pGetFloatVal)(3);
	printf("%f\n", f2);

	// 指针函数
	int* pReturn = getPointer();
	printf("%d\n", *pReturn);

	return 0;
}

