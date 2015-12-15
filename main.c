#include <stdio.h>
#include "multiple-length-arithmetic.h"

int mulTest(NUMBER *a, NUMBER *b, NUMBER *c)
{
	int i;
	int x, y;
	int result;
	int ope;

	puts("Test start...");

	for (i=0; i<10000; i++) {
		x = random()%10000;
		y = random()%10000;

		x *= (random() % 2 == 0) ? 1: -1;
        y *= (random() % 2 == 0) ? 1: -1;

		setInt(a,x);
		setInt(b,y);

		ope = x*y;

		multiple(a,b,c);
		getInt(c,&result);

		if (result != ope) {
			printf("ERROR\n");
			return -1;
		}
	}

	printf("Done.\n");
}

int main(void)
{
	int i;
	int test;
	NUMBER b,c,d;
	srandom(time(NULL));

	//mulTest(&b,&c,&d);

	setRnd(&b, 6);
	setRnd(&c, 1);

	multiple(&b,&c,&d);

	return 0;
}