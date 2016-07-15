#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int n,m;
	scanf("%d %d",&m,&n);
	int a[n][m];
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			scanf("%d",&a[i][j]);
	}

	return 0;
}
