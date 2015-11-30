#ifndef MULTIPLE_LENGTH_ARITHMETIC
#define MULTIPLE_LENGTH_ARITHMETIC

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define KETA 15

typedef struct 
{
	int n[KETA];
	int sign;
} NUMBER;

void setSign(NUMBER *a, int s);
int getSign(NUMBER *a);
void clearByZero(NUMBER *a);
void dispNumber(NUMBER *a);
void dispNumberZeroSuppress(NUMBER *a);
void sedRnd(NUMBER *a,int n);
void copyNumber(NUMBER *a, NUMBER *b);
void getAbs(NUMBER *a, NUMBER *b);
int isZero(NUMBER *a);
int mulBy10(NUMBER *a, NUMBER *b);
int divBy10(NUMBER *a, NUMBER *b);
void swap(NUMBER *a, NUMBER *b);
int setInt(NUMBER *a, int x);
int numComp(NUMBER *a, NUMBER *b);
int add(NUMBER *a, NUMBER *b, NUMBER *c);
int sub(NUMBER *a, NUMBER *b, NUMBER *c);



void setSign(NUMBER *a, int s) {
	if (s == -1 || s == 1)
		a->sign = s;
}

int getSign(NUMBER *a) {
	if (a->sign == -1 || a->sign == 1)
		return a->sign;
}

void clearByZero(NUMBER *a)
{
	int i;
	for (i=0; i<KETA; i++) {
		a->n[i] = 0;
	}

	setSign(a,1);
}

void dispNumber(NUMBER *a)
{
	int i;
	if (getSign(a) == 1) {
		printf("+");
	}
	else {
		printf("-");
	}
	for (i=KETA-1; i>=0; i--) {
		printf("%2d",a->n[i]);
	}
}

void dispNumberZeroSuppress(NUMBER *a)
{
	int i;
	int flag = 0;

	if (getSign(a) == 1) {
		printf("+");
	}
	else {
		printf("-");
	}

	for (i=KETA-1; i>=0; i--) {
		if (a->n[i] != 0) {
			flag = 1;
		}
		if (flag) {
			printf("%2d",a->n[i]);
		}
	}

}

void sedRnd(NUMBER *a,int n)
{
	int i;
	clearByZero(a);

	if (random()%100 > 50) {
		setSign(a,1);
	}
	else {
		setSign(a,-1);
	}
	for (i=0; i<n; i++) {
		a->n[i] = random()%10;
	}
}

void copyNumber(NUMBER *a, NUMBER *b)
{
	int i;
	setSign(b,getSign(a));
	for (i=0; i<KETA; i++) {
		b->n[i] = a->n[i];
	}
}

void getAbs(NUMBER *a, NUMBER *b)
{
	copyNumber(a, b);
	setSign(b,1);
}

int isZero(NUMBER *a)
{
	int i;
	if (getSign(a) == -1) {
		return -1;
	}
	for (i=0; i<KETA; i++) {
		if (a->n[i] != 0) {
			return -1;
		}
	}

	return 0;
}

int mulBy10(NUMBER *a, NUMBER *b)
{
	int i;
	copyNumber(a,b);

	for (i=KETA-1; i>0; i--) {
		b->n[i] = b->n[i-1];
	}

	b->n[0] = 0;

	if (a->n[KETA-1] != 0) {
		return -1;
	}

	return 0;
}

int divBy10(NUMBER *a, NUMBER *b)
{
	int i;
	copyNumber(a,b);

	for (i=0; i<KETA; i++) {
		b->n[i-1] = b->n[i];
	}

	b->n[KETA-1] = 0;

	if (a->n[0] != 0) {
		return -1;
	}

	return 0;
}

void swap(NUMBER *a, NUMBER *b)
{
	NUMBER tmp;
	copyNumber(a, &tmp);
	copyNumber(b, a);
	copyNumber(&tmp, b);	
}

int setInt(NUMBER *a, int x)
{
	int i,y;
	clearByZero(a);
	y = abs(x);

	if (x < 0) {
		setSign(a, -1);
	}
	else {
		setSign(a, 1);
	}

	for (i=0; i<10; i++) {
		a->n[i] = y % 10;
		y -= a->n[i];
		y /= 10;
	}

	if (KETA > 10)
		return -1;

	return 0;
}


int numComp(NUMBER *a, NUMBER *b)
{

	int i;

	if (getSign(a) == 1 && getSign(b) == -1) {
		return 1;
	}
	else if (getSign(a) == -1 && getSign(b) == 1) {
		return -1;
	}
	else if (getSign(a) == 1 && getSign(b) == 1) {

		for (i = KETA-1; i >= 0; i--)
		{
			if (a->n[i] > b->n[i])
				return 1;
			else if (a->n[i] < b->n[i])
				return -1;
		}
		return 0;
	}
	else if (getSign(a) == -1 && getSign(b) == -1) {

		for (i = KETA-1; i >= 0; i--)
		{
			if (a->n[i] > b->n[i])
				return -1;
			else if (a->n[i] < b->n[i])
				return 1;
		}
		return 0;
	}
}

int add(NUMBER *a, NUMBER *b, NUMBER *c)
{
	int d, e;
	int i;

	e = 0;
	clearByZero(c);

	for (i=0; i<KETA; i++) {
		d = a->n[i] + b->n[i] + e;
		c->n[i] = d % 10;
		e = d / 10;
	}

	if (e != 0) {
		return -1;
	}

	return 0;
}

int sub(NUMBER *a, NUMBER *b, NUMBER *c)
{
	int h = 0;
	int i;

	clearByZero(c);
	switch(numComp(a,b)) {
		case -1 :	for (i=0; i<KETA; i++) {
						a->n[i] -= h;
						if (b->n[i] >= a->n[i]) {
							c->n[i] = b->n[i] - a->n[i];
							h = 0;
						}
						else if (b->n[i] < a->n[i]) {
							c->n[i] = 10 + b->n[i] - a->n[i];
							h = 1;
						}
					}
					setSign(c, -1);
					break;

		default:	for (i=0; i<KETA; i++) {
						a->n[i] -= h;
						if (a->n[i] >= b->n[i]) {
							c->n[i] = a->n[i] - b->n[i];
							h = 0;
						}
						else if (a->n[i] < b->n[i]) {
							c->n[i] = 10 + a->n[i] - b->n[i];
							h = 1;
						}
					}
					break;
	}

	if (h!=0) {
		return -1;
	}

	return 0;
}


#endif