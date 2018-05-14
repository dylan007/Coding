#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a[5][5] = {{1,1,1,1,1},
			{1,1,1,1,1},
			{1,1,1,1,1},
			{1,1,1,1,1},
			{1,1,1,1,1}};
	int i,j,x;
	for(i=1;i<=3;i++)
	{
		for(j=1;j<=3;j++)
		{
			scanf("%d",&x);
			a[i][j] += x;
			a[i-1][j] += x;
			a[i+1][j] += x;
			a[i][j+1] += x;
			a[i][j-1] += x;
		}
	}
	
	for(i=1;i<=3;i++)
	{
		for(j=1;j<=3;j++)
			printf("%d",a[i][j]&1);
		printf("\n");
	}

	return 0;
}
