#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int modexp(int x,int pow,int mod)
{
	int y=1;
	int u=x%mod;
	while(pow>0)
	{
		if(pow%2 != 0)
			y = (y*u)%mod;
		pow = pow/2;
		u = (u*u)%mod;
		printf("y = %d u = %d pow = %d\n",y,u,pow);
	}
}

int main()
{
	int x,mod,pow;
	scanf("%d %d %d",&x,&pow,&mod);
	modexp(x,pow,mod);
	return 0;
}
