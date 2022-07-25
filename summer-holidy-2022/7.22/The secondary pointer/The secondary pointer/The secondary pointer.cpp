#include <stdio.h>
void fuction(int value)
{
	printf("子函数内部：%x\t%x\n", value, &value);
	value = 0x1000;
	printf("子函数内部：%x\t%x\n", value, &value);
}

void fuctionP(int* pValue)
{
	printf("子函数内部：%x\t\t%x\t\t%x\n", *pValue, pValue, &pValue);
	//实验一：给一级指针赋值
	int b = 0x1000;
	pValue = &b;
	//实验二：给int赋值
	//*pValue = 0x1000;
	printf("子函数内部：%x\t\t%x\t\t%x\n", *pValue, pValue, &pValue);

}

void fuctionPP(int** ppValue)
{
	printf("子函数内部：%x\t%x\t%x\t%x\n", **ppValue, *ppValue, ppValue, &ppValue);
	
	//实验一：给二级指针赋值
	int c = 0x1000;
	int* pValue = &c;
	ppValue = &pValue;

	//实验二：给一级指针赋值
	//int c = 0x1000;
	//int* pValue = &c;
	//*ppValue = pValue;
	
	//实验三：给int 赋值
	//**ppValue = 0x1000;
	
	printf("子函数内部：%x\t%x\t%x\t%x\n", **ppValue, *ppValue, ppValue, &ppValue);	
}


void fuctionPPP(int*** pppValue)
{
	printf("子函数内部：%x\t%x\t%x\t%x\t%x\n", ***pppValue, **pppValue, *pppValue, pppValue, &pppValue);
	
	//实验一:给三级指针赋值
	//int d = 0x1000;
	//int* pValue = &d;
	//int** ppValue = &pValue;
	//pppValue = &ppValue;
	// 
	//实验二：给二级指针赋值
	//int d = 0x1000;
	//int* pValue = &d;
	//int** ppValue = &pValue;
	//*pppValue = ppValue;

	//实验三：给一级指针赋值
	//int d = 0x1000;
	//int* pValue = &d;
	//**pppValue = pValue;

	//实验四：给int赋值
	***pppValue = 0x1000;

	printf("子函数内部：%x\t%x\t%x\t%x\t%x\n", ***pppValue, **pppValue, *pppValue, pppValue, &pppValue);

}

int main()
{
	int a = 100;
	int* p1 = &a;
	int** pp2 = &p1;
	int*** ppp3 = &pp2;
	
	printf("before:%x\t%x\n", a, &a);
	fuction(a);
	printf("after:%x\t%x\n", a, &a);

	printf("\nbefore:%x\t%x\t%x\n", *p1, p1, &p1);
	fuctionP(p1);
	printf("after:%x\t%x\t%x\n", *p1, p1, &p1);

	printf("\nbefore:%x\t%x\t%x\t%x\n", **pp2, *pp2,pp2, &pp2);
	fuctionPP(pp2);
	printf("after:%x\t%x\t%x\t%x\n", **pp2, *pp2, pp2, &pp2);

	printf("\nbefore:%x\t%x\t%x\t%x\t%x\n", ***ppp3, **ppp3, *ppp3, ppp3, &ppp3);
	fuctionPPP(ppp3);
	printf("after:%x\t%x\t%x\t%x\t%x\n", ***ppp3, **ppp3, *ppp3, ppp3, &ppp3);

	return 0;
}