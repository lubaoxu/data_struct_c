#include <stdio.h>



int main()
{
	{
		int i = 10;
		printf("%d\t%d\n", i, &i);
	}
	{
		int i = 20;
		printf("%d\t%d\n", i, &i);

	}
}