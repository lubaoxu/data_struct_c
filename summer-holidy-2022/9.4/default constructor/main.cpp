
#include <iostream>

#include "constructor.h"


constructor fun(constructor a, constructor b) {
	constructor c;
	return c;
}

constructor fun1(constructor a, constructor b) {
	return a;
}


constructor & fun2(constructor & a, constructor &b) {
	return a;
}

int main()
{
	/*constructor s;
	constructor t(s);
	constructor w ;
	//w = t;
	w.operator=(t);
	//constructor* p=&s;
	s.operator&();
	*/

	constructor s;
	constructor w;
	//fun(s,w);
	//fun1(s,w);
	fun2(s,w);
	

	return 10;
}
