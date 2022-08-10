#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int nArray[10] = { 0 };
	int* p = nArray;
	int* p1 = &(nArray[0]);

	printf("%d", nArray);
	printf("%d", &(nArray[0]));

	(* p) = &nArray;

	return 0;
}