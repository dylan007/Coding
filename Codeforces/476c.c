#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>

#define MOD 1000000007

int main()
{
	long long int a,b;
	scanf("%I64d %I64d",&a,&b);
	long long int A,B,C,D;
	A = (a*(a+1)/2)%MOD;
	B = (b*(b-1)/2)%MOD;
	C = (A*b+a)%MOD;
	D = (B*C)%MOD;
	printf("%I64d\n",D);
	return 0;
}
