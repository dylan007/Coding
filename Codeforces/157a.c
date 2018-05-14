#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,i,j;
	scanf("%d",&n);
	int a[n][n];
	int sumrow[n];
	for(i=0;i<n;i++)
	{
		sumrow[i] = 0;
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
			sumrow[i] += a[i][j];
		}
	}
	int sumcol[n];
	for(j=0;j<n;j++)
	{
		sumcol[j]=0;
		for(i=0;i<n;i++)
			sumcol[j] += a[i][j];
	}
	int c=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			c += (sumcol[j] > sumrow[i]);
	}
	printf("%d\n",c);
	return 0;
}
