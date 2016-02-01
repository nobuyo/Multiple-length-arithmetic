#ifndef MULTIPLE_LENGTH_ARITHMETIC
#define MULTIPLE_LENGTH_ARITHMETIC

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define DIGIT 1200

typedef struct 
{
	int n[DIGIT];
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
int simpleMultiple(NUMBER *, NUMBER *, NUMBER *);
int multiple(NUMBER *, NUMBER *, NUMBER *);
int simpleDivide(int, int, int *, int *);
int divide(NUMBER *, NUMBER *, NUMBER *, NUMBER *);
int power(NUMBER *, NUMBER *, NUMBER *);
int isPrime(NUMBER *);


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
	for (i=0; i<DIGIT; i++) {
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
	for (i=DIGIT-1; i>=0; i--) {
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

	for (i=DIGIT-1; i>=0; i--) {
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
	for (i=0; i<DIGIT; i++) {
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
	for (i=0; i<DIGIT; i++) {
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

	for (i=DIGIT-1; i>0; i--) {
		b->n[i] = b->n[i-1];
	}

	b->n[0] = 0;

	if (a->n[DIGIT-1] != 0) {
		return -1;
	}

	return 0;
}

int divBy10(NUMBER *a, NUMBER *b)
{
	int i;
	copyNumber(a,b);

	for (i=0; i<DIGIT; i++) {
		b->n[i-1] = b->n[i];
	}

	b->n[DIGIT-1] = 0;

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

int setInt(NUMBER *num, int x) {
	int i = 0;
	clearByZero(num);

	// if negative
	if (x < 0) {
		setSign(num, -1);
		x *= -1;
	}

	while (1) {
		// break if overflow
		if (i >= DIGIT) return -1;
		num->n[i++] = x % 10;
		// break if finish
		if (x / 10 == 0) break;
		x /= 10;
	}
	return 0;
}

int getInt(NUMBER *a, int *x) {

    int i;
    *x = 0;

    for (i = 0; i < DIGIT; i++) {
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
    int sign = getSign(a);
    if (getSign(a) > getSign(b)){
    	return  1;
    }

    if (getSign(a) < getSign(b)){
    	return -1;
    }

    for (i = DIGIT-1; i >= 0; i--) {
        if (a->n[i] > b->n[i]) return  1 * sign;
        if (a->n[i] < b->n[i]) return -1 * sign;
    }
    return 0;
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

	for (i=0; i<DIGIT; i++) {
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

	for (i=0; i<DIGIT; i++) {
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
	// swap(b,a);

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

int simpleMultiple(NUMBER *n1, NUMBER *n2, NUMBER *result)
{
	int i,j,k;
	int carry = 0;
	int r;
	int top_j=DIGIT-1,top_i=DIGIT-1;

	NUMBER tmp, _result;

	clearByZero(result);
	clearByZero(&_result);
	clearByZero(&tmp);

	while (n2->n[top_i] == 0) {
		top_i--;
	}
	while (n1->n[top_j] == 0) {
		top_j--;
	}

	// printf("%d\n", top_j);
	// printf("%d\n", top_i);

	for (i = 0; i <= top_i+1; i++) {
		NUMBER tmp2, tmp3;
		clearByZero(&tmp2);

		for (j = 0; j <= top_j+1; j++) {
			int mul = n1->n[j] * n2->n[i] + carry;
			tmp2.n[j]  = mul % 10;
			carry = mul / 10;
		}

		for (k = 0; k < i; k++) {
			r = mulBy10(&tmp2, &tmp3);
			if (r != 0) return -1;
			copyNumber(&tmp3, &tmp2);
		}

		r = add(&tmp, &tmp2, &_result);
		if (r != 0) return -1;
		copyNumber(&_result, &tmp);
	}

	copyNumber(&tmp, result);

	return 0;
}

int multiple(NUMBER *multiplicand, NUMBER *
multiplier, NUMBER *result)
{
	NUMBER absMultiplicand;
	NUMBER absMultiplier;
	int r;
	getAbs(multiplicand, &absMultiplicand);
	getAbs(multiplier, &absMultiplier);

	int sign1 = getSign(multiplicand) == 1 ? 1:0;
	int sign2 = getSign(multiplier)   == 1 ? 1:0;

	if (sign1 && sign2) {
		r = simpleMultiple(multiplicand, multiplier, result);
		setSign(result, 1);
	}
	else if (sign1 && !sign2) {
		r = simpleMultiple(multiplicand, &absMultiplier, result);
		setSign(result, -1);
	}
	else if (!sign1 && sign2) {
		r = simpleMultiple(&absMultiplicand, multiplier, result);
		setSign(result, -1);
	}
	else if (!sign1 && !sign2) {
		r = simpleMultiple(&absMultiplicand, &absMultiplier, result);
		setSign(result, 1);
	}
	else {
		return -1;
	}

	if (r == -1)
//		printf("err:underflow\n");

	return r;
}

// int divide(NUMBER *dividend, NUMBER *divisor, NUMBER *quotient, NUMBER *remainder)
// {
// 	NUMBER tmp,tmp_div;
// 	NUMBER divisor_;
// 	clearByZero(&tmp);
// 	clearByZero(&tmp_div);
// 	clearByZero(quotient);
// 	clearByZero(remainder);
// 	clear_by_zero(&divisor_);
//     get_abs(dividend, &tmp_div);
//     get_abs(divisor, &divisor_);

// 	if (isZero(divisor) == 0) {
// 		puts("Error! divide by zero, abort");
// 		return -1;
// 	}


// 	while (1) {
// 		if (numComp(&tmp_div,&divisor_) < 0) break;
// 		increment(quotient, &tmp);
// 		copyNumber(&tmp, quotient);
// 		sub(&tmp_div,&divisor_,&tmp);
// 		copyNumber(&tmp, &tmp_div);
// 	}
// 	copyNumber(&tmp_div,remainder);

// 	if (isZero(quotient) != 0) {
// 		setSign(quotient, getSign(dividend) * getSign(divisor));
// 	}
// 	if (isZero(remainder) != 0) {
// 		setSign(remainder, getSign(dividend));
// 	}

// 	return 0;
// }

int column_divide(NUMBER *dividend, NUMBER *divisor, NUMBER *quotient, NUMBER *remainder)
{
    NUMBER dividend_, divisor_;
    NUMBER tmp;
    int count = 0;
    int i;
    clearByZero(quotient);
    clearByZero(remainder);
    clearByZero(&tmp);
    clearByZero(&dividend_);
    clearByZero(&divisor_);

    getAbs(dividend, &dividend_);
    getAbs(divisor, &divisor_);

    if (isZero(divisor) == 0) return -1;

    while (numComp(&dividend_, &divisor_) == 1) {
        mulBy10(&divisor_, &tmp);
        if (numComp(&dividend_, &tmp) != 1) break;
        copyNumber(&tmp, &divisor_);
        count++;
    }

    for (i = 0; i <= count; i++) {
        mulBy10(quotient, &tmp); copyNumber(&tmp, quotient);
        while (numComp(&dividend_, &divisor_) > -1) {
            increment(quotient, &tmp);
            copyNumber(&tmp, quotient);
            sub(&dividend_, &divisor_, &tmp);
            copyNumber(&tmp, &dividend_);
        }
        divBy10(&divisor_, &tmp);
        copyNumber(&tmp, &divisor_);
    }
    copyNumber(&dividend_, remainder);

    if (isZero(quotient) != 0) {
        setSign(quotient, getSign(dividend) * getSign(divisor));
    }
    if (isZero(remainder) != 0) {
        setSign(remainder, getSign(dividend));
    }

    return 0;
}

// int power(NUMBER *mantissa, NUMBER *expo, NUMBER *result)
// {
// 	int i=0, _expo;
// 	NUMBER tmp;
// 	getInt(expo, &_expo);
// 	clearByZero(&tmp);
// 	clearByZero(result);
// 	setInt(result, 1);

// 	if (_expo < 0) return -1;
// 	if (_expo == 0) return 0;
	
// 	while (i < _expo)
// 	{
// 		if (i >= _expo) break;
// 		multiple(result, mantissa, &tmp);
// 		copyNumber(&tmp, result);
// 		i++;
// 	}
// 	return 0;
// }

// c <- pow(a, b)
int power(NUMBER *a, NUMBER *b, NUMBER *c) {
    NUMBER zero, one;
    NUMBER i, tmpI;
    NUMBER result, tmpResult;
    clearByZero(&zero);
    setInt(&one, 1);
    clearByZero(&i);
    clearByZero(&tmpI);
    clearByZero(&result);
    clearByZero(&tmpResult);

    // pow(a, b) where a == 0
    if (numComp(a, &zero) == 0) {
        setInt(c, 0);
        return 0;
    }

    // pow(a, b) where a == 1
    if (numComp(a, &one) == 0) {
        setInt(c, 1);
        return 0;
    }

    // pow(a, b) where b == 0
    if (numComp(b, &zero) == 0) {
        setInt(c, 1);
        return 0;
    }

    // pow(a, b)
    setInt(&result, 1);
    while (1) {
        if (numComp(&i, b) >= 0) break;

        // result *= a
        multiple(a, &result, &tmpResult);
        copyNumber(&tmpResult, &result);

        // i++
        increment(&i, &tmpI);
        copyNumber(&tmpI, &i);
    }
    copyNumber(&result, c);

    return 0;
}


#endif