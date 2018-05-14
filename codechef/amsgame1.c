#include<stdio.h>
#include<stdlib.h>

int gcd(int a,int b)
{
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,i,x,curr;
		scanf("%d",&n);
		scanf("%d",&x);
		curr = x;
		n--;
		while(n--)
		{
			scanf("%d",&x);
			curr = gcd(x,curr);
		}
		printf("%d\n",curr);
	}
	return 0;
}
