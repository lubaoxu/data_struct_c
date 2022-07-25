#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

int array_pointer()
{
    int a[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
    int i, j;
    int(*p)[4] = a;
    printf("%d\t%d\t%d\t%d\n", sizeof(a), sizeof(*p), sizeof(p[0]), sizeof(p[0][0]));
    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%-2d\x20", *(*(p + i) + j));
        }
        printf("\n");
    }
    return 0;

}
//数组指针传参
int test(int(*p)[4])//p是一个指向int型数组长度是4的指针
{
    int i, j;
    printf("%d\t%d\t%d\t%d\n", sizeof(p), sizeof(*p), sizeof(p[0]), sizeof(p[0][0]));

    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%-2d\x20", *(*(p + i) + j));
        }
        printf("\n");
    }
    return 0;
}


int main()
{
    int twoDimensionArray[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
    test(twoDimensionArray);
    return 0;
}
