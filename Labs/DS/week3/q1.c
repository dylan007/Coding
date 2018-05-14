#include <stdio.h>

void mul(int m1[][1000],int m2[][1000],int m3[][1000],int n,int m,int q,int row)
{
	int i,j,k;
	if(row == n)
		return;
	for(i=0;i<q;i++)
	{
		m3[row][i] = 0;
		for(j=0;j<m;j++)
			m3[row][i] += m1[row][j] * m2[j][i];
	}
	mul(m1,m2,m3,n,m,q,row+1);
	return;
}

void read(int m1[][1000],int n,int m)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			scanf("%d",&m1[i][j]);
	}
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int p,q;
	scanf("%d %d",&p,&q);
	if(m!=p)
		printf("Multiplication not possible");
	int m1[n][1000];
	int m2[p][1000];
	int m3[n][1000];
	read(m1,n,m);
	read(m2,p,q);
	mul(m1,m2,m3,n,m,q,0);
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			printf("%d ",m3[i][j]);
		printf("\n");
	}
	return 0;
}