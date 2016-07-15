#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>

int prime[5000000];

void sieve()
{
	int i,j;
	for(i=2;i*i<=5000000;i++)
	{
		if(prime[i]==0)
		{
			for(j=i*i;j<=5000000;j+=i)
				prime[j]=1;
		}
	}
}

int main()
{
	memset(prime,0,4*5000000);
	sieve();
	int i;
	prime[0]=prime[1]=1;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int x,y,t;
		scanf("%d %d",&x,&y);
		if(x>y)
		{
			t = x;
			x = y;
			y = t;
		}
		int ans=0;
		while(y>=x)
		{
			if(prime[y]==0)
				ans-=y;
			else
				ans+=y;
			y/=2;
		}
		printf("%d\n",ans);
	}
	return 0;
}
