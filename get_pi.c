#include <stdio.h>
#include <math.h>

double bbp_sum(double i,double j)
{
	double sum;
	sum = (1.0/pow(16.0,i)) * (1.0/((8.0*i)+j));
	return sum;
}

int main(void)
{
	double i;
	double numer;
	double denom;
	double frac;
	double ans=0;

	for (i=0; i<1000; i++) {
		ans += 4*bbp_sum(i,1) - 2*bbp_sum(i,4) - bbp_sum(i,5) -bbp_sum(i,6);
		printf("%f\n", ans);
	}

	printf("%f\n", ans);
}