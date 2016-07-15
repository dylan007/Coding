#include<stdio.h>
#include<stdlib.h>
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long int x;
		scanf("%ld",&x);
		(x%4 == 1)?printf("ALICE\n"):printf("BOB\n");
	}
	return 0;
}
