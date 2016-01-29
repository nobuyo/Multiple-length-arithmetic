#include <stdio.h>
#include "multiple-length-arithmetic.h"

int main(void)
{
	int i;
	NUMBER tmp;
	NUMBER frac,frac_;
	NUMBER one,two,four,five,six,eight,ten,sixteen,sousand;
	NUMBER one_,two_,four_;
	NUMBER denominator;
	NUMBER denom8;
	NUMBER denom16,denom16_;
	NUMBER n;
	NUMBER trash;
	NUMBER ans;

	clearByZero(&ans);
	clearByZero(&frac);


	setInt(&one,1);
	setInt(&two,2);
	setInt(&four,4);
	setInt(&ten,10);
	setInt(&sousand,1000);

	puts("10^1000");
	power(&ten, &ten, &tmp);
	power(&tmp, &ten, &tmp);
	power(&tmp, &ten, &tmp);

	multiple(&one,&tmp,&one_);
	multiple(&two,&tmp,&two_);
	multiple(&four,&tmp,&four_);

	setInt(&one_,1);
	setInt(&two_,2);
	setInt(&four_,4);
	setInt(&five,5);
	setInt(&six,6);
	setInt(&eight,8);
	setInt(&sixteen,16);
	setInt(&denom16,16);

	puts("main loop");
	for (i=0; i<1000; i++) {

		// printf("%d.. ",i);
		setInt(&n,i);

		// 8n
		// puts("8n");
		multiple(&n,&eight,&denom8);

		// 16^n
		// puts("16^n");
		if (i == 0) {
			setInt(&denom16, 1);
		}
		else {
			multiple(&denom16,&sixteen,&denom16_);
			copyNumber(&denom16_, &denom16);
		}

		// 4/(8n+1)
		// puts("4/8n+1");
		add(&denom8,&one_,&denominator);
		column_divide(&four,&denominator,&tmp,&trash);
		add(&frac, &tmp, &frac_);
		copyNumber(&frac_, &frac);

		// -2/(8n+4)
		// puts("-2/(8n+4)");
		add(&denom8,&four_,&denominator);
		column_divide(&two,&denominator,&tmp,&trash);
		sub(&frac, &tmp, &frac_);
		copyNumber(&frac_, &frac);

		// -1/(8n+5)
		// puts("-1/(8n+5)");
		add(&denom8,&five,&denominator);
		column_divide(&one,&denominator,&tmp,&trash);
		sub(&frac, &tmp, &frac_);
		copyNumber(&frac_, &frac);

		// -1/(8n+6)
		// puts("-1/(8n+6)");
		add(&denom8,&six,&denominator);
		column_divide(&one,&denominator,&tmp,&trash);
		sub(&frac, &tmp, &frac_);
		copyNumber(&frac_, &frac);

		// dispNumber(&frac);
		// putchar('\n');
		// dispNumber(&denom16);
		// putchar('\n');

		// (...)/16^n
		column_divide(&frac,&denom16,&tmp,&trash);

		// dispNumber(&tmp);
		// putchar('\n');

		add(&tmp, &ans, &trash);
		copyNumber(&trash,&ans);
		// dispNumber(&ans);
		// putchar('\n');


	}

	dispNumber(&ans);
	putchar('\n');

	return 0;
}