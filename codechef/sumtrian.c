#include<stdio.h>
#include<stdlib.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,i,j;
		scanf("%d",&n);
		int a[n][n];
		for(i=0;i<n;i++)
		{
			for(j=0;j<=i;j++) scanf("%d",&a[i][j]);
		}
		for(i=n-2;i>=0;i--)
		{
			for(j=0;j<=i;j++)
				a[i][j] += (a[i+1][j]>=a[i+1][j+1])?a[i+1][j]:a[i+1][j+1];
		}
		printf("%d\n",a[0][0]);
	}
	return 0;
}
