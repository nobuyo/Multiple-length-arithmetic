#include <stdio.h>
#include "multiple-length-arithmetic.h"

void bbp_sum(NUMBER *sum, NUMBER *c,NUMBER *one,NUMBER *eight)
{	
	NUMBER tmp,tmp_;

	add(eight, c, &tmp);
	column_divide(one,&tmp,sum,&tmp_);
}

int get10pow1000(NUMBER *a)
{
	clearByZero(a);
	a->n[1000]=1;
	return 0;
}

int main(void)
{
	int i;
	NUMBER tmp,_tmp;
	NUMBER sum1,sum2,sum3,sum4;
	NUMBER n;
	NUMBER ans;
	NUMBER numer, denom, denom16;
	NUMBER coff,hex;
	NUMBER one,two,four,five,six,ten,sousand,eight,sixteen;

	clearByZero(&tmp);
	clearByZero(&_tmp);
	clearByZero(&ans);
	clearByZero(&denom16);

	setInt(&one,1);
	setInt(&two,2);
	setInt(&four,4);
	setInt(&five,5);
	setInt(&six,6);
	setInt(&ten,10);
	setInt(&sousand,1000);
	setInt(&eight,8);
	setInt(&sixteen,16);
	setInt(&hex,1);

	get10pow1000(&coff);

	puts("main loop");
	for (i=0; i<20; i++) {

		setInt(&n,i);

		multiple(&eight,&n,&denom);

		bbp_sum(&sum1,&one,&coff,&denom);
		bbp_sum(&sum2,&four,&coff,&denom);
		bbp_sum(&sum3,&five,&coff,&denom);
		bbp_sum(&sum4,&six,&coff,&denom);


		multiple(&sum1,&four,&tmp);
		sum1 = tmp;
		// copyNumber(&tmp,&sum1);

		multiple(&sum2,&two,&tmp);
		sum2 = tmp;
		// copyNumber(&tmp,&sum2);

		sub(&sum1,&sum2, &tmp);
		sub(&tmp, &sum3, &_tmp);
		sub(&_tmp,&sum4, &tmp);

		add(&ans, &tmp, &_tmp);
		ans = _tmp;

		add(&denom16,&hex,&tmp);
		denom16 = tmp;
		multiple(&hex,&sixteen,&tmp);
		hex = tmp;

		// copyNumber(&_tmp,&ans);

		// dispNumber(&ans);
		// putchar('\n');
	}

	add(&denom16, &hex, &denom);
	column_divide(&ans, &denom, &tmp, &_tmp);

	dispNumber(&tmp);
	putchar('\n');


	return 0;
}

