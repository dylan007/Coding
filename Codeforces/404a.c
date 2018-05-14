#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,i,j,flag=1;
	scanf("%d",&n);
	char a[n][n],c;
	for(i=0;i<n;i++)
	{
		c = getchar();
		for(j=0;j<n;j++)
		{
			c = getchar();
			a[i][j] = c;	
		}
	}
	for(i=0;i<n;i++)
	{
		if((a[0][0] != a[i][i])||(a[0][0] != a[i][n-i-1]))
		{
			flag = 0;
			break;
		}
	}
	if(flag)	
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if((i!=j)&&(i != n-1-j))
				{
					if((a[0][0] == a[i][j])||(a[1][0] != a[i][j]))
					{
						flag = 0;
						break;
					}
				}
			}
		}
	}
	if(flag)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
