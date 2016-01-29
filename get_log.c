#include <stdio.h>
#include <math.h>

double get_log(double x)
{
	int i;
	double y = 0;
	double n;
	double p = (x-1.0) / (x+1.0);
	for (i=0; i<1000000; i++) {
		n = (2*i)+1;
		y +=  pow(p, n)/n;
		//printf("%f\n",y);
	}
	return y;
}

int main(void)
{
	printf("%f\n",get_log(3.0));
}