#include<stdio.h>
#include<stdlib.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,c=0;
		scanf("%d",&n);
		c = (n/7)*7;
		c -= ((n-c)%4)*7;
		printf("%d\n",(c>=0)?c:-1);
	}
}
