#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define phi ((1+sqrt(5))/2)

long long unsigned fib(unsigned n){ return floor( ( pow(phi,n) - pow(1-phi,n) ) / sqrt(5));}

unsigned num(unsigned x)
{
	double a = log(x*sqrt(5))/log(phi) + 0.5;
	x = a;
	return x;
}

int main()
{
	long long unsigned a;
	unsigned n,pos;
	scanf("%u",&n);
	pos = num(n);
	if(n == 0)
		printf("0 0 0\n");
	else if(n == 1)
		printf("1 0 0\n");
	else if(n == 2)
		printf("1 1 0\n");
	else if(n == 3)
		printf("1 1 1\n");
	else
		printf("%I64u %I64u %I64u\n",fib(pos-4),fib(pos-3),fib(pos-1));
	return 0;
}
