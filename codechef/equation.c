#include<stdio.h>
#include<stdlib.h>

long long int f(long long int n)
{
	if(n<0)
		return 0;
	else
		return ((n+1)*(n+2)*(n+3))/6;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int n,a,b,c,ans;
		scanf("%lld %lld %lld %lld",&n,&a,&b,&c);
		ans = f(n)-f(n-a-1)-f(n-b-1)-f(n-c-1)+f(n-a-b-2)+f(n-a-c-2)+f(n-b-c-2)-f(n-a-b-c-3);
		printf("%lld\n",ans);
	}
	return 0;
}
