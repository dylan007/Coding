#include<stdio.h>
#include<stdlib.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,x,y,i;
		scanf("%d %d %d",&n,&x,&y);
		for(i=x;i<n;i += x)
		{
			if(i%y != 0)
				printf("%d ",i);
		}
		printf("\n");
	}
	return 0;
}
