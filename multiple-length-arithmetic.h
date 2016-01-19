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

void setSign(NUMBER *, int);
int getSign(NUMBER *);
void clearByZero(NUMBER *);
void dispNumber(NUMBER *);
void dispNumberZeroSuppress(NUMBER *);
void setRnd(NUMBER *,int);
void copyNumber(NUMBER *, NUMBER *);
void getAbs(NUMBER *, NUMBER *);
int isZero(NUMBER *);
int mulBy10(NUMBER *, NUMBER *);
int divBy10(NUMBER *, NUMBER *);
void swap(NUMBER *, NUMBER *);
int setInt(NUMBER *, int);
int getInt(NUMBER *, int *);
int numComp(NUMBER *, NUMBER *);
int add(NUMBER *, NUMBER *, NUMBER *);
int sub(NUMBER *, NUMBER *, NUMBER *);
int increment(NUMBER *, NUMBER *);
int decrement(NUMBER *, NUMBER *);
int simpleMultiple(int, int, int *);
int multiple(NUMBER *, NUMBER *, NUMBER *);
int simpleDivide(int, int, int *, int *);
int divide(NUMBER *, NUMBER *, NUMBER *, NUMBER *);
int power(NUMBER *, NUMBER *, NUMBER *);

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

void setRnd(NUMBER *a, int n)
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

int getInt(NUMBER *a, int *x) {

    int i;
    *x = 0;

    for (i = 0; i < KETA; i++) {
        *x += a->n[i] * pow(10, i);
    }
    if (a->sign == -1) {
        *x *= -1;
    }
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
	int d, carry;
	int i;
	int result;
	NUMBER abs_val1,abs_val2;

	carry = 0;
	clearByZero(c);

	if (getSign(a) == 1 && getSign(b) == -1) {
		getAbs(b,&abs_val1);
		result = sub(a,&abs_val1,c);
		return result;
	}

	if (getSign(a) == -1 && getSign(b) == 1) {
		getAbs(a,&abs_val1);
		result = sub(b,&abs_val1,c);
		return result;
	}
	
	if (getSign(a) == -1 && getSign(b) == -1) {
		getAbs(a,&abs_val1);
		getAbs(b,&abs_val2);
		result = add(&abs_val1, &abs_val2, c);
        setSign(c, -1);
        return result;
    }

	for (i=0; i<KETA; i++) {
		d = a->n[i] + b->n[i] + carry;
		c->n[i] = d % 10;
		carry = d / 10;
	}

	if (carry != 0) {
		return -1;
	}

	return 0;
}

int sub(NUMBER *a, NUMBER *b, NUMBER *c)
{
	int borrow = 0;
	int h;
	int i;
	int result;
	NUMBER abs_val;

	clearByZero(c);

	if (getSign(b) == -1) {
		getAbs(b, &abs_val);
		result = add(a,&abs_val,c);
		return result;
	}

	if (getSign(a) == -1 && getSign(b) == 1) {
		getAbs(a,&abs_val);
		result = add(&abs_val, b, c);
		setSign(c, -1);
		return result;
	}


	//---sub---

	if (numComp(a,b) == -1) {
		swap(a,b);
		setSign(c,-1);
	}

	for (i=0; i<KETA; i++) {
		h = a->n[i] - borrow;
		if (h >= b->n[i]) {
			c->n[i] = h - b->n[i];
			borrow = 0;
		} 
		else {
			c->n[i] = h - b->n[i] + 10;
			borrow = 1;
		}

	}
	swap(b,a);

	if (borrow != 0) {
		return -1;
	}

	return 0;
}

int increment(NUMBER *a, NUMBER *b)
{
	NUMBER one;
	int r;

	setInt(&one, 1);
	r = add(a, &one, b);

	return r;
}

int decrement(NUMBER *a, NUMBER *b)
{
	NUMBER one;
	int r;

	setInt(&one, 1);
	r = sub(a, &one, b);

	return r;
}

int simpleMultiple(int a, int b, int *c)
{
	int i;
	int multiplier   = (a > b) ? b : a;
    int multiplicand = (a > b) ? a : b;

	*c = 0;

	for (i=0; i<b; i++) {
		*c += a;
	}

	return 0;
}

int multiple(NUMBER *a, NUMBER *b, NUMBER *c)
{
	int i,j;
	int carry = 0;
	int e = 0;
	int result = 0;

	NUMBER d,ans;

	clearByZero(c);
	clearByZero(&ans);

	for (i=0; i<KETA-1; i++) {
		clearByZero(&d);
		carry = 0;

		for (j=0; j<KETA; j++) {
			e = a->n[j] * b->n[i] + carry;
			d.n[j+i] = e%10;
			carry = e /10 %10;
		}

		if (carry != 0) {
			result = -1;
		}

		result = add(&d,c,&ans);
		copyNumber(&ans, c);
	}
	return result;
}

int simpleDivide(int x, int y, int *z, int *w)
{
	int k;

	if (y==0) {
		return -1;
	}

	k = 0;
	while (1) {
		if (x < y) break;
		x -= y;
		k++;
	}

	*z = k;
	*w = x;

	return 0;
}

int divide(NUMBER *a, NUMBER *b, NUMBER *c, NUMBER *d)
{
	NUMBER m,n,one;
	clearByZero(c);
	clearByZero(d);
	
	if (isZero(b) == 0) {
		puts("Error! divide by zero, abort");
		return -1;
	}

	copyNumber(a,&n);

	while (1) {
		if (numComp(&n, b) == -1)
			break;
		else {
			increment(c,&m);
			copyNumber(&m,c);
			sub(&n,b,&m);
			copyNumber(&m,&n);
		}
	}
	copyNumber(&n,d);
}

int power(NUMBER *a, NUMBER *b, NUMBER *c)
{
	NUMBER i;
	setInt(&i,0);
	printf("loop\n");
	while (1)
	{
		if (numComp(b, &i) != 1 ) break;
		increment(&i);
	}
}

#endif