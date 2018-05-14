#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int sqr(int n)
{
	int x;
	x = sqrt(n);
	return (x*x == n);
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,i,x,b;
		scanf("%d",&n);
		b = sqrt(n);
		if(sqr(n))
			printf("0\n");
		else
		{
			if(n%2 == 0)
				x = 1;
			else
			{
				if(b%2 == 0)
					b += 1;
				x = 2;
			}
			for(i=b;i;i-=x)
			{
				if(n%i == 0)
				{
					printf("%d\n",(n/i - i));
					break;
				}
			}
		}
	}
	return 0;
}
