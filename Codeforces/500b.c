#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmpfunc(const void *a,const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int n;
	scanf("%d",&n);
	int a[n],b[n];
	int check[n][n];
	int i,j;
	for(i=0;i<n;i++)
	{
			scanf("%d",&a[i]);
			b[i] = a[i];
	}
	qsort(b,n,sizeof(int),cmpfunc);
	int c[n],t;
	char C;
	getchar();
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			C = getchar();
			check[i][j] = (C=='0')?0:1;
		}
		getchar();
	}
	int k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				if(check[i][j]==1 && check[j][k]==1)
					check[i][k]=1;
			}
		}
	}
	for(i=0;i<n;i++)
		c[i]=a[i];
	for(i=0;i<n;i++)
	{
		if(a[i]!=b[i])
		{
			for(j=0;j<n;j++)
			{
				if(a[j]==b[i])
				{
					if(check[i][j]==1)
					{
						t = c[i];
						c[i] = c[j];
						c[j] = t;
					}
					t = a[i];
					a[i]=a[j];
					a[j]=t;
				}
			}
		}
	}
	for(i=0;i<n;i++)
		printf("%d ",c[i]);
	printf("\n");
	return 0;
}
