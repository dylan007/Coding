#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{ 
		int x,c=0,i,t;
		scanf("%d",&x);
		for(i=11;i>=0;i--)
		{
			t = pow(2,i);
			t = x/t;
			x -= t*pow(2,i);
			c += t;
		}
		printf("%d\n",c);
	}
	return 0;
}
