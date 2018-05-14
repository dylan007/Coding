#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int a[n][m],b[n][m];
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	}
	
	return 0;
}
