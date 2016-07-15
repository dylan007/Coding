#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i,x=1,y=1,n,m,count=0;
	scanf("%d %d",&n,&m);
	printf("%d\n",(n+m-1));
	if(n<m)
	{
		for(i=0;i<(n+m-1);i++)
		{
			printf("%d %d\n",x,y);
			if(i%2 == 0)
			{
				if(y<m)
					y++;
				else 
					x++;
			}
			else
			{
				if(x<n)
					x++;
				else
					y++;
			}
		}	
	}
	else
	{
		for(i=0;i<(n+m-1);i++)
		{
			printf("%d %d\n",x,y);
			if(i%2 == 0)
			{
				if(x<n)
					x++;
				else
					y++;
			}
			else
			{
				if(y<m)
					y++;
				else
					x++;
			}
		}
	
	}
	return 0;
}
