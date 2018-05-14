#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,i;
	scanf("%d",&n);
	int mon[n],c=0;
	for(i=0;i<n;i++)
		scanf("%d",&mon[i]);
	for(i=0;i<n;i++)
	{
		c=0;
		while(mon[i]>0)
		{
			if(i>0)
			{
				if(c>0)
					printf("LRP");
				else
				{
					printf("P");
					c = 1;
				}
				mon[i]--;
			}
			else
			{
				if(c>0)
					printf("RLP");
				else
				{
					printf("P");
					c=1;
				}
				mon[i]--;
			}
		}
		if(i != n-1)
			printf("R");
	}
	printf("\n");
	return 0;
}
