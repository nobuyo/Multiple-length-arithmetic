#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define eps 1.e-8

double inverse2(double);
double inverse3(double);
double inverse4(double);
double inverse5(double);

int main(int argc, char **argv)
{
	double a = 1234.0;
	double b;
	double r2,r3,r4,r5;

	b = 1.0 / a;
	r2 = inverse2(a);
	r3 = inverse3(a);
	r4 = inverse4(a);
	r5 = inverse5(a);

	printf("	   a = %5.16lf\n", a);
	printf("true 1/a = %5.16lf\n", b);
	printf("	  r2 = %5.16lf\n", r2);
	printf("	  r3 = %5.16lf\n", r3);
	printf("	  r4 = %5.16lf\n", r4);
	printf("	  r5 = %5.16lf\n", r5);

	return 0;
}

double inverse2(double a)
{
	double x;
	double y;
	double g;

	x = 0.2 * pow(10.0, -(double)((int)log10(a)));

	while (1)
	{
		y = x;
		x = y * (2.0 - a * y);
		g = fabs(x - y);
		if (g <= eps) break;
	}

	return x;
}

double inverse3(double a)
{
	double x;
	double y;
	double g;
	double h;

	x = 0.2 * pow(10.0, -(double)((int)log10(a)));

	while (1)
	{
		y = x;
		h = 1.0 - a * y
		x = y * (1.0 + h + h * h);
		g = fabs(h);
		if (g <= eps) break;
	}

	return x;
}

double inverse4(double a)
{
	double x;
	double y;
	double g;
	double h;

	x = 0.2 * pow(10.0, -(double)((int)log10(a)));

	while (1)
	{
		y = x;
		h = 1.0 - a * y
		x = y * (1.0 * h) * (1.0 + h * h);
		g = fabs(h);
		if (g <= eps) break;
	}

	return x;
}

double inverse5(double a)
{
	double x;
	double y;
	double g;
	double h;

	x = 0.2 * pow(10.0, -(double)((int)log10(a)));

	while (1)
	{
		y = x;
		h = 1.0 - a * y
		x = y * (1.0 * (1.0 + h * h) * (h + h * h));
		g = fabs(h);
		if (g <= eps) break;
	}

	return x;
}