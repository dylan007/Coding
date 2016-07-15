#include<stdio.h>
#include<stdlib.h>

int gcd(int a, int b)
{
	return (b != 0)? gcd(b,a%b):a;
}

int main()
{
	int lcm,x,y,a,b;
	scanf("%d%d%d%d",&x,&y,&a,&b);
	lcm = (x*y)/gcd(x,y);
	if(a%lcm == 0)
		a = a/lcm;
	else
		a = a/lcm + 1;
	b = b/lcm;
	printf("%d\n",b-a+1);
	return 0;
}
