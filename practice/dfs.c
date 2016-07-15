#include<stdio.h>
#include<stdlib.h>
int st[500],f[500];
int state[500],p[500];
int time;
void visitdfs(int g1[500][500],int v,int nov)
{
	int i;
	for(i=0;i<nov;i++)
	{
		printf("v=%d,i=%d\n",v,i);
		if(g1[v][i]==1&&state[i]==0)
		{
			p[i]=v;
			state[i]=1;
			st[i]=time++;
			visitdfs(g1,i,nov);
		}
	}
	state[v]=2;
	f[v]=time++;
}
void dfs(int g1[500][500],int nov)
{
	int i;
	for(i=0;i<nov;i++)
	{
		state[i]=0;
		p[i]=-1;
	}
	 time=1;
	for(i=0;i<nov;i++)
	{
		if(state[i]==0)
		{
			state[i]=1;
			st[i]=time++;
			visitdfs(g1,i,nov);
		}
	}
}	

int main()
{
	int nov,noe,i,j,t;
	scanf("%d",&t);
	int v1,v2;
	for(i=0;i<t;i++)
	{
		scanf("%d %d",&nov,&noe);
		int g1[500][500]={0};
		int g2[500][500]={0};
		for(j=0;j<noe;j++)
		{
			scanf("%d %d",&v1,&v2);
			g1[v1][v2]=1;
			g2[v2][v1]=1;

		}
		printf("%d",g1[3][1]);
		dfs(g1,nov);
		for(i=0;i<nov;i++)
			printf("%d",f[i]);

	}
	return 0;
}
