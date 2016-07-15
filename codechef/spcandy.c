#include<stdio.h>
#include<stdlib.h>
int main()
{
	long long int t,n,k,i;
	scanf("%lld",&t);
	for(i=0;i<t;i++)
	{
		scanf("%lld%lld",&n,&k);
		if(k==0)
			printf("0 %lld\n",n);
		else
			printf("%lld %lld\n",(n/k),(n%k));
	}
	return 0;
}	
