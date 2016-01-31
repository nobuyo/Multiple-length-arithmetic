#include <stdio.h>
#include "multiple-length-arithmetic.h"

void bbp_sum(NUMBER *sum,NUMBER *n,NUMBER *c,NUMBER *one,NUMBER *eight ,NUMBER *sixteen)
{	
	NUMBER tmp,tmp_;
	NUMBER denom;
	NUMBER hex;

	power(sixteen,n,&tmp);
	column_divide(one,&tmp,&hex,&tmp_);

	multiple(eight,n,&tmp);
	add(&tmp, c, &tmp_);
	column_divide(one,&tmp_,&denom,&tmp);

	multiple(&hex,&denom,sum);
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
	NUMBER coff;
	NUMBER one,two,four,five,six,ten,sousand,eight,sixteen;

	clearByZero(&tmp);
	clearByZero(&_tmp);
	clearByZero(&ans);

	setInt(&one,1);
	setInt(&two,2);
	setInt(&four,4);
	setInt(&five,5);
	setInt(&six,6);
	setInt(&ten,10);
	setInt(&sousand,1000);
	setInt(&eight,8);
	setInt(&sixteen,16);

	get10pow1000(&coff);

	dispNumber(&coff);
	putchar('\n');

	puts("main loop");
	for (i=0; i<1000; i++) {
		setInt(&n,i);
		bbp_sum(&sum1,&n,&one,&coff,&eight,&sixteen);
		bbp_sum(&sum2,&n,&four,&coff,&eight,&sixteen);
		bbp_sum(&sum3,&n,&five,&coff,&eight,&sixteen);
		bbp_sum(&sum4,&n,&six,&coff,&eight,&sixteen);


		multiple(&sum1,&four,&tmp);
		sum1 = tmp;
		// copyNumber(&tmp,&sum1);

		multiple(&sum2,&two,&tmp);
		sum2 = tmp;
		// copyNumber(&tmp,&sum2);

		sub(&sum1,&sum2,&tmp);
		sub(&tmp,&sum3,&_tmp);
		sub(&_tmp,&sum4,&tmp);

		add(&ans,&tmp,&_tmp);
		ans = _tmp;
		// copyNumber(&_tmp,&ans);

		dispNumber(&ans);
		putchar('\n');
	}

	dispNumber(&ans);
	putchar('\n');


	return 0;
}

