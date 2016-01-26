#include <stdio.h>

int main(void)
{
	int i;
	for (i=13401; i<=13440; i++) {
		printf("%d=>%2d ",i,i%11);
		if (i % 5 == 0) putchar('\n');
	}

	return 0;
}