#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>

int main()
{
	int r,c;
	scanf("%d %d%*C",&r,&c);
	char inp[r][c];
	int check[r][c];
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			inp[i][j]=getchar();
			check[i][j]=0;
		}
		getchar();
	}
	int count=0;
	for(i=0;i<r;i++)
	{
		int f=0;
		for(j=0;j<c;j++)
		{
			if(inp[i][j]!='.')
			{
				f=1;
				break;
			}
		}
		if(f==0)
		{	
			for(j=0;j<c;j++)
			{
				count += (check[i][j]==0);
				check[i][j]=1;
			}
		}
	}
	for(i=0;i<c;i++)
	{
		int f=0;
		for(j=0;j<r;j++)
		{
			if(inp[j][i]!='.')
			{
				f=1;
				break;
			}
		}
		if(f==0)
		{
			for(j=0;j<r;j++)
			{
				count += (check[j][i]==0);
				check[j][i]=1;
			}
		}
	}
	printf("%d\n",count);
	return 0;
}
