#include <iostream>

#include "Student.h"

int main()
{
	char name1[10] = "asdf";
	char name2[10] = { 0 };
	Student lbx(18, (char*) "asdf");
	Student lby(19, "asdf");
	//问题：Student 的构造函数中，第二个参数，不能从"const char 数组" 转化为 "char 数组"
	//解法一："const char 数组" 转化为 "char * "
	//解法二：把拷贝构造函数中加上 const 修饰符

	Student max;
	max = Max(lbx, lby);
	std::cout << "max" << max.m_pName << std::endl;
	std::cout << "max obj " << max << std::endl;
	return 0;
}