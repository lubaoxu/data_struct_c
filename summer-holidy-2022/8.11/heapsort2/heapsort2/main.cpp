#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "heapsort.h"
#include "utils.h"

int main(void)
{
	int nArray[] = { 56,38,26,75,56,22,18,69,92,45 };
	makeHeap(nArray, sizeof(nArray)/sizeof(nArray[0]));
	output(nArray, sizeof(nArray) / sizeof(nArray[0]));
	return 0;
}

