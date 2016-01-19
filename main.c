#include <stdio.h>
#include "multiple-length-arithmetic.h"

int main(void)
{
	int i;
	int test,x,y;
	NUMBER a,b,c,d;
	srandom(time(NULL));

	// simpleDivide(16,5,&x,&y);

	// printf("%d/%d = %d...%d\n", 16, 5, x, y);

	setRnd(&a,3);
	setRnd(&b,1);
	power(&a,&b,&c);
	dispNumber(&a);
	putchar('\n');
	dispNumber(&b);
	putchar('\n');

	return 0;
}