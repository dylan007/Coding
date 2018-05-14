#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	long long int n,m,a,x,b,c;
	scanf("%lld %lld",&n,&m);
	a = n+2;
	b = n+2*n;
	c = a + (b-a)/2;
	while(m--)
	{
		scanf("%lld",&x);
		if(x>=a && x<=b)
		{
			if(x<=c)
				printf("%lld\n",x-a+1);
			else
				printf("%lld\n",b-x+1);
		}
		else
			printf("0\n");
	}
	return 0;
}	
