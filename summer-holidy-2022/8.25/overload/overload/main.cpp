// overload.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#include "viecle.h"
#include "car.h"


int main()
{

    // vftable virtual  function table  虚拟函数表   void ** 

    Viecle * pV = new Viecle();
    pV->run();
    std::cout  << sizeof(*pV) << std::endl;

    Car* pCar = new Car();
    pCar->run();

    Viecle* pCar2 = pCar;
    pCar2->run();

    std::cout << std::endl;

    std::cout << typeid(*pV).name() << std::endl;
    std::cout << typeid(*pCar).name() << std::endl;
    std::cout << typeid(*pCar2).name() << std::endl;

}
