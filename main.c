#include <stdio.h>
#include "multiple-length-arithmetic.h"

int main(void)
{
	int i;
	int test,x,y;
	NUMBER a,b,c,d;
	srandom(time(NULL));

	setInt(&a,300);
	setInt(&b,10);

	dispNumber(&a);
	putchar('\n');
	dispNumber(&b);
	putchar('\n');
	divide(&a,&b,&c,&d);

	dispNumber(&c);
	putchar('\n');
	dispNumber(&d);
	putchar('\n');

	setInt(&a,5);
	setInt(&b,2);

	dispNumber(&a);
	putchar('\n');
	dispNumber(&b);
	putchar('\n');
	power(&a,&b,&c);

	dispNumber(&c);
	putchar('\n');

	return 0;
}