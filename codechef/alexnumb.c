#include<stdio.h>
#include<stdlib.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int n;
		scanf("%lld",&n);
		int a;
		printf("%lld\n",(n*(n-1))/2);
		while(n--) scanf("%d",&a);
	}
	return 0;
}
