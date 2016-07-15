#include<stdio.h>
#include<stdlib.h>
int main()
{
	long long int n,k,x,count=0;
	scanf("%lld%lld",&n,&k);
	while(n--)
	{
		scanf("%lld",&x);
		if(x%k==0)
			count++;
	}
	printf("%lld\n",count);
	return 0;
}
