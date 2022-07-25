#include "link.h"

#include <stdio.h>

void readIntLink(IntLinkData * link) {
	while (link != NULL ) {
		printf("%d\n", link->value);
		link = link->pNext;
	}
}
