#include<stdio.h>
#include<stdlib.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		printf("%d %d\n",(a>b)?a:b,a+b);
	}
	return 0;
}
