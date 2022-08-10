#include <iostream>

struct Data {
    int nVal;
};

void function(int nVal) {
    printf("in function() nVal:%d\t&nVal:%x\n", nVal, &nVal);
    int jj = nVal;
}

int functionWithReturn() {
    int nVal = 500;
    printf("in function() nVal:%d\t&nVal:%x\n", nVal, &nVal);
    return nVal;
}

int main()
{
    // part 1 查看 i和j的地址是否一致？
    int i = 100;
    int j = i;
    printf("&i:%x\t&j:%x\t\t\t\ti:%d\tj:%d\n", &i,&j, i, j);

    // part 2 
    printf("\n");
    int nVal = 200;
    printf("in main() nVal:%d\t&nVal:%x\n", nVal,&nVal);
    function(nVal);

    // part 3
    printf("\n");
    nVal = functionWithReturn();
    printf("in function() nVal:%d\t&nVal:%x\n", nVal, &nVal);
    
    // part 4
    printf("\n");
    printf("part 4 begin: nVal:%d\t&nVal:%x\n", i, &i);
    {
        int i = 800;
        printf("part 4 middle: nVal:%d\t&nVal:%x\n", i, &i);
    }
    printf("part 4 end: nVal:%d\t&nVal:%x\n", i, &i);

    // part 5
    printf("\n");
    int nArray[10] = { 0 };
    nArray[0] = 900;
    int kk = nArray[0];


    printf("\n");
    Data dataArray[10] = { 0 };  // 在栈上
    //Data* pDataArray = (Data*)malloc(sizeof(Data)*10);
    dataArray[0].nVal = 900;
    Data data = dataArray[0]; // ***** 拷贝构造函数
    Data * pData = &(dataArray[0]);
    Data* pData2 = dataArray;

    return 0;
}
