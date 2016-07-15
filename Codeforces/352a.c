#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>

int main()
{
	int n;
	scanf("%d",&n);
	int c0=0,c9=0;
	int i,x;
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		c0 += (x==0);
		c9 += (x==5);	
	}
	if(c0==0)
		printf("-1\n");
	else
	{
		if(c9 == 0)
		{
			if(c0 == 0)
				printf("-1\n");
			else
				printf("0\n");
		}
		else
		{
			while(c9>=0)
			{
				if(c9%9 == 0)
				{
					if(c9==0)
					{
						if(c0>0)
							printf("0\n");
						else
							printf("-1\n");
					}
					else
					{
						for(i=0;i<c9;i++)
							printf("5");
						for(i=0;i<c0;i++)
							printf("0");
						printf("\n");
					}
					break;
				}
				c9--;
			}
		}
	}
	return 0;
}
