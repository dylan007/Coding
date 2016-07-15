#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int a[100][100];

int main()
{
	int n,m;
	scanf("%d %d",&m,&n);
	int b[m][n];
	int i,j,flag=0;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&b[i][j]);
			flag = (b[i][j]>flag)?b[i][j]:flag;
			a[i][j]=1;
		}
	}
	int f=0;
	int k,p;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(b[i][j]==0)
			{
				for(k=0;k<m;k++)
					a[k][j]=0;
				for(p=0;p<n;p++)
					a[i][p]=0;
			}
		}
	}
	int F=0;
	for(i=0;i<m;i++)
	{
		int x=0;
		for(j=0;j<n;j++)
		{
			F=0;
			x=0;
			for(k=0;k<m;k++)
				x = x||a[k][j];
			for(k=0;k<n;k++)
				x = x||a[i][k];
			if(x!=b[i][j])
			{
				F=1;
				break;
			}
		}
		if(F==1)
			break;
	}
	if(F==1)
		printf("NO\n");
	else
	{
		printf("YES\n");
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
				printf("%d ",a[i][j]);
			printf("\n");
		}
	}
	return 0;
}
