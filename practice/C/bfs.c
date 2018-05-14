#include<stdio.h>
#include<stdlib.h>
int dist[1000];
int parent[1000];
void bfs(int a[][1000],int visited[],int s,int nov)
{
	int q[1000],f=-1,r=-1,i,j;
	for(i=0;i<nov;i++)
	{
		dist[i]=-1;
		parent[i]=-1;
	}
	dist[s]=0;
	parent[s]=-1;
	q[++r]=s;
	visited[s]=1;
	int v;
	while(r!=f)
	{
		v=q[++f];
		for(i=0;i<nov;i++)
		{
			if(a[v][i]==1&&visited[i]==0)
			{
				visited[i]=1;
				dist[i]=dist[v]+1;
				parent[i]=v;
				q[++r]=i;
			}
			//q[++r]=i;
		}
		visited[v]=2;
	}
}
int main()
{
	int nov,i,j;
	scanf("%d",&nov);
	int a[1000][1000];
	for(i=0;i<nov;i++)
		for(j=0;j<nov;j++)

		{
			scanf("%d",&a[i][j]);
		}
	int visited[1000]={0};
	int start;
	scanf("%d",&start);
	bfs(a,visited,start,nov);
	for(i=0;i<nov;i++)
		printf("%d--",dist[i]);
	return 0;
}
