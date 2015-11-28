#include <stdio.h>
#include "multiple-length-arithmetic.h"

int compare2Num(int a, int b)
{
	if (a > b) {
		return 1;
	}
	else if (a < b) {
		return -1;
	}
	else if (a == b) {
		return 0;
	}
}

void compTest(NUMBER *a, NUMBER *b)
{
	int i;
	int x, y;
	int resultOpe, resultCmp;
	x = random();
	y = random();

	setInt(a, x);
	setInt(b, y);

	for (i=0; i<10000; i++) {
		resultOpe = compare2Num(x,y);
		resultCmp = numComp(a,b);
		if(resultCmp == resultOpe)
			printf("OK\n");
		else
			printf("NG\n");
	}
}


int main(void)
{
	int i;
	int test;
	NUMBER b,c,d;
	srandom(time(NULL));


	for (i=0; i<KETA; i++) {
		b.n[i] = i;
		c.n[i] = i;
		d.n[i] = i;
	}

	b.sign = 1;
	c.sign = 0;
	d.sign = 1;

	clearByZero(&b);

	b.n[0] = 5;
	b.n[1] = 3;

	dispNumber(&b);
	putchar('\n');

	dispNumberZeroSuppress(&b);
	putchar('\n');

	sedRnd(&b,8);
	dispNumber(&b);
	putchar('\n');

	printf("Zero Check => %d\n", isZero(&b));

	clearByZero(&c);
	dispNumber(&c);
	putchar('\n');

	getAbs(&b,&c);
	dispNumber(&c);
	putchar('\n');

	sedRnd(&b,8);
	sedRnd(&c,8);
	dispNumber(&b);
	putchar('\n');
	dispNumber(&c);
	putchar('\n');
	swap(&b,&c);
	dispNumber(&b);
	putchar('\n');
	dispNumber(&c);
	putchar('\n');

	test = random();
	printf("%d\n", test);
	setInt(&b,test);
	dispNumber(&b);
	putchar('\n');

	//compTest(&b,&c);

	return 0;
}