// constrctor.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#include "Data.h"

//#define XXX

void  fun(Data data) {
    printf("fun(Data data) &data:%x\n", &data);
}

void  fun(Data* pData) {
    printf("fun(Data* data) &*data:%x\n", &*pData);
}

Data  fun() {
    Data d(100);
    printf("fun() &*data:%x\n", &d);
    return d;
}
;
Data*  fun1() {
    Data d(200);
    printf("fun1() &*data:%x\n", &d);
    return &d;
}

int main()
{
    if (0) {

    Data data;
//    Data array[10] = { 0 };

    Data* pData = (Data*)malloc(sizeof(Data));
    //Data* pData[] = (Data * [])malloc(sizeof(Data));  // todo by lbs

    Data* pData1 = new Data();
    Data* pData2 = new Data(10.0);
    Data* pData3 = new Data(10, (char *)"lbx");

    delete pData1;
    delete pData2;
    delete pData3;

    // 先释放堆。
    }
      
    //fun(50); // @lbs 调用之前构建的Data对象，如何传递到形参的？

    int ii = 100;
    int& jj = ii;
    ii = 101;


#ifdef XXX
  Data data8(150);

  Data data9(data8);

   fun(data8);
    fun(&data8);

    return 0;

#endif


    Data d8 = fun();
    //Data * pData8 = fun1();

    return 0;
}

