
#include <iostream>

#include "A.h"

int main()
{
	B* pB = new B;
	pB->fun();
	pB->gun();

	A* pA = new B;
	pA->fun();//fun这个成员函数是非virtual虚拟函数类型，执行函数时，会依赖于指向这个对象所指向的类型，而不是依赖于对象的实际类型。
	pA->gun();//gun这个成员是函数是virtual虚拟函数类型，执行函数时，会使用对象的实际类型。（这是C++多态的特性）
	
	//int nASize = sizeof(A);
	//i/nt nBSize = sizeof(B);



	return 0;
}
