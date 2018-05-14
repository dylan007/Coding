#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>

int main()
{
	long long int N,n,f;
	scanf("%lld",&n);
	N = n/2;
	f = n%2;
	printf("%lld\n",(N*(N+1))-((N+f)*(N+f)));
	return 0;
}
