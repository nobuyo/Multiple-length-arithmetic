#include <stdio.h>
#include "multiple-length-arithmetic.h"

void bbp_term(NUMBER *term,NUMBER *n,NUMBER *c,NUMBER *one,NUMBER *eight ,NUMBER *sixteen)
{	
	NUMBER tmp,tmp_;

	add(eight, c, &tmp);
	column_divide(one,&tmp,term,&tmp_);
}

int get10pow1000(NUMBER *a)
{
	clearByZero(a);
	a->n[1010]=1;
	return 0;
}

int main(void)
{
	int i;
	NUMBER tmp,_tmp;
	NUMBER term1,term2,term3,term4;
	NUMBER sum;
	NUMBER n;
	NUMBER ans;
	NUMBER coff,hex;
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
	setInt(&hex,1);

	get10pow1000(&coff);

	puts("main loop");
	for (i=0; i<1000; i++) {
		setInt(&n,i);

		// 8n
		multiple(&eight, &n ,&tmp);

		bbp_term(&term1,&n,&one,&coff,&tmp,&hex);
		bbp_term(&term2,&n,&four,&coff,&tmp,&hex);
		bbp_term(&term3,&n,&five,&coff,&tmp,&hex);
		bbp_term(&term4,&n,&six,&coff,&tmp,&hex);


		multiple(&term1,&four,&tmp);
		term1 = tmp;
		// copyNumber(&tmp,&term1);

		multiple(&term2,&two,&tmp);
		term2 = tmp;
		// copyNumber(&tmp,&term2);

		sub(&term1,&term2,&tmp);
		sub(&tmp,&term3,&_tmp);
		sub(&_tmp,&term4,&tmp);

		column_divide(&tmp,&hex,&sum,&_tmp);

		multiple(&hex,&sixteen,&tmp);
		hex = tmp;

		add(&ans,&sum,&tmp);
		ans = tmp;
		// copyNumber(&_tmp,&ans);

		// dispNumber(&ans);
		// putchar('\n');
	}

	dispNumber(&ans);
	putchar('\n');


	return 0;
}

