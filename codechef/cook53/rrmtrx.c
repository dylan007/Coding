#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>

#define MOD 10000007

int perm[38];

/*int next_perm(int n,int m)
{
	int i;
	int f=1;
	for(i=0;i<m;i++)
	{
		if(perm[i]<n)
		{
			f=0;
			break;
		}
	}
	if(f==1)
		return 1;
	for(i=m-1;i>=0;i--)
	{
		if(perm[i]<n)
			break;
	}
	perm[i]++;
	i++;
	for(;i<m;i++)
		perm[i]=1;
	return 0;
}*/

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int mat[n][m];
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&mat[i][j]);
			perm[j]=1;
		}
	}
	int ans=0,t=0;
	int temp=1;
	j=0;
	for(i=0;i<m;i++)
	{
		ans = 0;
		for(j=0;j<n;j++)
			ans+=mat[j][i];
		temp = (temp*ans)%MOD;
	}
	printf("%d\n",temp);
	/*
	while(t==0)
	{
		for(i=0;i<m;i++)
			printf("%d ",perm[i]);
		printf("\n");
		temp=1;
		for(i=0;i<m;i++)
		{
			printf("%d ",mat[perm[i]-1][i]);
			temp = (temp*mat[perm[i]-1][i])%MOD;
		}
		printf("\n\n");
		ans += temp;
		t = next_perm(n,m);
	}
	printf("%d\n",ans);
	*/
	return 0;
}
