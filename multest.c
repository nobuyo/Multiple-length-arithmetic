#include <stdio.h>
#include "multiple-length-arithmetic.h"

int main(void)
{
	int i;
	int x, y;
	int result;
	int ope;
	NUMBER a,b,c;

	puts("Test start...");

	for (i=0; i<10; i++) {
		x = random()%100;
		y = random()%100;

		x *= (random() % 2 == 0) ? 1: -1;
        y *= (random() % 2 == 0) ? 1: -1;

		setInt(&a,x);
		setInt(&b,y);

		ope = x*y;

		multiple(&a,&b,&c);
		getInt(&c,&result);

		if (result != ope) {
			printf("ERROR\n");
			return -1;
		}
	}

	printf("Done.\n");
	return 0;
}