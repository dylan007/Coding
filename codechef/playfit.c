#include<stdio.h>
#include<stdlib.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int j,n,i,max=0,c=0;
		scanf("%d",&n);
		int x1,x2;
		scanf("%d",&x1);
		for(i=0;i<n-1;i++)
		{
			scanf("%d",&x2);
			if(x2<=x1) x1=x2;
			else
			{
				c = x2-x1;
				if(c>max) max = c;
			}
		}
		if(max>0)
			printf("%d\n",max);
		else
			printf("UNFIT\n");
	}
	return 0;
}
