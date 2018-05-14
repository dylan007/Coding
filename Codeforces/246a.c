#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i,n;
	scanf("%d",&n);
	if(n>=3)
	{
		for(i=n;i>0;i--)
			printf("%d ",i);
		printf("\n");
		return 0;
	}
	printf("-1\n");
	return 0;
}
