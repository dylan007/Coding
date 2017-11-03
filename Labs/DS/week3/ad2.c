#include <stdio.h>
#include <stdlib.h>

int check(int v[][100],int arr[][100],int n,int x,int y)
{
	if(v[x][y])
		return;
}

int main()
{
	int n;
	scanf("%d",&n);
	int arr[n][100];
	int i,j;
	int x,y;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&arr[i][j]);
			if(arr[i][j])
			{
				x = i;
				y = j;
			}
		}
	}
	int flag,visited[n][100] = {0};
	flag=check(visited,arr,n,x,y);
	return 0;
}