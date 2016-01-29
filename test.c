#include <stdio.h>
#include "multiple-length-arithmetic.h"

int main(void)
{
	NUMBER a,b,c,d;

	setRnd(&a, 40);
	setRnd(&b,  1);

	dispNumber(&a);
	putchar('\n');
	dispNumber(&b);
	putchar('\n');

	column_divide(&a,&b,&c,&d);

	dispNumber(&c);
	putchar('\n');
	dispNumber(&d);
	putchar('\n');
}