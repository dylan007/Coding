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
		if( 360%n == 0 )
			printf("y ");
		else
			printf("n ");
		if(n<=360)
			printf("y ");
		else
			printf("n ");
		if(((n*(n+1))/2) <= 360)
			printf("y\n");
		else
			printf("n\n");
	}
	return 0;
}
