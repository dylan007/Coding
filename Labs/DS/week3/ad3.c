#include <stdio.h>
#include <stdlib.h>

int flag=0;

int trav(int v[][1000],int m[][1000],int x1,int y1,int x2,int y2,int n)
{
	if(x1<0 || x1>=n)
		return 0;
	if(y1<0 || y1>=n)
		return 0;
	if(x2<0 || x2>=n)
		return 0;
	if(y2<0 || y2>=n)
		return 0;
	if(m[x1][y1] == 0)
		return 0;
	if(x1==x2 && y1==y2)
	{
		printf("%d %d\n",x2,y2);
		flag=1;
		return 1;
	}
	if(v[x1][y1])
		return 0;
	v[x1][y1] = 1;
	int ans=0;
	ans += trav(v,m,x1+1,y1,x2,y2,n);
	ans += trav(v,m,x1-1,y1,x2,y2,n);
	ans += trav(v,m,x1,y1+1,x2,y2,n);
	ans += trav(v,m,x1,y1-1,x2,y2,n);
	if(ans)
	{	
		printf("%d %d\n",x1,y1);
		return 1;
	}
	else
		return 0;
}

int main()
{
	int n;
	scanf("%d",&n);
	int m[n][1000];
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			scanf("%d",&m[i][j]);
	}
	int x1,x2,y1,y2;
	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	int v[1000][1000] = {0};
	flag=0;
	trav(v,m,x1,y1,x2,y2,n);
	if(flag)
		printf("Path exists\n");
	else
		printf("Path doesn't exist\n");
	return 0;
}