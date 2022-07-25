#include "link.h"
#include <stdio.h>
void readstudent(Peoplestudent* link)
{
	while (link != NULL)
	{
		printf("%d\n", link->number);
		link = link->pNext;
	}
	while (link != NULL)
	{
		printf("%d\n", link->age);
		link = link->pNext;
	}
}