#include<stdio.h>
#include<stdlib.h>

int tp(long long int x)
{
	int i,flag=0;
	for(i=2;i<=(x/2);i++)
	{
		if(x%i == 0)
		{
			if(flag == 0)
				flag=1;
			else
				return 0;
		}
	}
	return flag;
}

int main()
{
	int n,i;
	long long int x;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&x);
		if(tp(x))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
