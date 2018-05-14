#include<stdio.h>
#include<stdlib.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		if(n%2 == 0)
			printf("ALICE\n");
		else
			printf("BOB\n");
	}
	return 0;
}
