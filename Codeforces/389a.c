#include<stdlib.h>
#include<stdio.h>

int gcd(int a, int b)
{
	if(b == 0)
	       return a;
	else
		return gcd(b,a%b);	
}

int main()
{
	int n,i,min=100,max=0;
	scanf("%d",&n);
	int x[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&x[i]);
		max = max>x[i]?max:x[i];
		min = min<x[i]?min:x[i];
	}
	int mingc = min;
	int j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j != i)
				mingc = mingc<gcd(x[i],x[j]) ? mingc:gcd(x[i],x[j]);
		}
	}
	for(i=0;i<n;i++)
	{
		if(x[i]%mingc != 0)
		{
			printf("%d\n",n);
			return 0;
		}
	}
	printf("%d\n",n*mingc);
	return 0;
}
