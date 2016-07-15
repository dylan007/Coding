#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	if(n<m)
		printf("-1\n");
	else
	{
		int i;
		for(i=1;;i++)
		{
			if(i*m<=n && 2*i*m>=n)
			{
				int x,y;
				x = n-i*m;
				y = i*m-x;
				printf("%d\n",x+y);
				return 0;
			}
			else if(i*m>=n)
				break;
		}
		printf("-1\n");
	}
	return 0;
}
