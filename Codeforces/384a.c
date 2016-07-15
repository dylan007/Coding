#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,i,j,ans;
	char c;
	scanf("%d",&n);
	if(n%2 == 0)
		printf("%d\n",(n*n)/2);
	else
		printf("%d\n",((n*(n-1)/2)+(n+1)/2));
	for(i=0;i<n;i++)
	{
		if(i%2 == 0)
		{
			for(j=0;j<n;j++)
			{
				if(j%2 == 0)
					printf("C");
				else
					printf(".");
			}
		}
		else
		{
			for(j=0;j<n;j++)
			{
				if(j%2 == 0)
					printf(".");
				else
					printf("C");
			}
		}
		printf("\n");
	}
	return 0;
}
