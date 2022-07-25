#include "link.h"
#include <stdio.h>
void tryfun(tryA* link,int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		printf("%d\n", link[i].a);
	}
}