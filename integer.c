#include <stdio.h>
#include "multiple-length-arithmetic.h"

void getDenom(NUMBER *denom, int x)
{
	int i;
	NUMBER tmp,_tmp;
	NUMBER num;
	NUMBER n;
	int coef[5] = {256,512,356,97,75};

	for (i=0; i<5; i++) {
		setInt(&n,x);
		setInt(&num,4-i);
		power(&n,&num,&tmp);
		setInt(&num,coef[i]);
		multiple(&tmp,&num,&_tmp);

		add(&_tmp, denom, &tmp);
		copyNumber(&tmp,denom);
	}
	puts("getDenom Done.");
}

void getNumer(NUMBER *numer, int x)
{
	int i;
	NUMBER tmp,_tmp;
	NUMBER num;
	NUMBER n;
	int coef[4] = {64,140,107,27};

	for (i=0; i<4; i++) {
		setInt(&n,x);
		setInt(&num,3-i);
		power(&n,&num,&tmp);
		setInt(&num,coef[i]);
		multiple(&tmp,&num,&_tmp);

		add(&_tmp, numer, &tmp);
		copyNumber(&tmp,numer);
	}
	puts("getNumer Done.");
}

void getFrac(NUMBER *denom, NUMBER *numer, NUMBER *tmp)
{
	NUMBER _tmp,ten,sousand;
	clearByZero(tmp);
	setInt(&sousand,1000);
	power(&ten, &sousand, tmp);
	multiple(numer,tmp,&_tmp);
	copyNumber(&_tmp, numer);
	column_divide(numer,denom,tmp,&_tmp);
	puts("getFrac Done.");
}

void divBy16n(NUMBER *num, NUMBER *denom16, NUMBER *result)
{
	NUMBER n;
	NUMBER tmp,_tmp,sixteen;
	setInt(&sixteen,16);
	multiple(denom16, &sixteen, &tmp);
	column_divide(num,&tmp,result,&_tmp);
	puts("divBy16n Done.");
}

int main(void)
{
	int i;
	NUMBER tmp,_tmp;
	NUMBER denom,numer;
	NUMBER denom16;
	NUMBER n;
	NUMBER ans;

	clearByZero(&denom);
	clearByZero(&numer);
	clearByZero(&tmp);
	clearByZero(&_tmp);
	clearByZero(&ans);

	setInt(&denom16,1);

	puts("main loop");
	for (i=0; i<100; i++) {

		printf("-----%d-----\n",i);
		getDenom(&denom,i);
		// dispNumber(&denom);
		// putchar('\n');
		getDenom(&numer,i);
		// dispNumber(&numer);
		// putchar('\n');
		getFrac(&numer,&denom,&tmp);
		divBy16n(&tmp,&denom16,&_tmp);
		add(&ans,&_tmp,&tmp);
		copyNumber(&tmp, &ans);
	}

	dispNumber(&ans);
	putchar('\n');

	return 0;
}

