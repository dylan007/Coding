#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define mo 1000000007

int n,m,a[100005],c[100105][115];
int f[115][100050];

int main()
{
	int i,k,j;
	scanf("%d%d",&n,&m);
	for(i = 1;i<=n;i++)scanf("%d",&a[i]);
	for(i = 0;i<=100010;i++)
		for(j = 0;j<=i&&j<=100;j++)
			c[i][j]=(i&&j)?(c[i-1][j]+c[i-1][j-1])%mo:1;
	while(m--)
	{
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		f[k][l]++;
		for(i=k;i>=0;i--)
			f[i][r+1]=(f[i][r+1]-c[r-l+k-i][k-i])%mo;
	}
	for(k=100;k>=0;k--)
		for(i=1;i<=n;i++)
		{
			f[k][i]=(0ll+f[k][i]+f[k+1][i]+f[k][i-1])%mo;
		}
	for(i=1;i<=n;i++)printf("%d ",((a[i]+f[0][i])%mo+mo)%mo);
	printf("\n");
	return 0;
}
