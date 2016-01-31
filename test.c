#include <stdio.h>
#include "multiple-length-arithmetic.h"

int main(void)
{
	NUMBER a,b,c,d;
	
	setInt(&a, 2);
	setInt(&b,10);

	power(&a,&b,&c);

	dispNumber(&a);
	putchar('\n');
	dispNumber(&b);
	putchar('\n');
	dispNumber(&c);
	putchar('\n');
}