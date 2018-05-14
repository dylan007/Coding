#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

long long int a[500][500];

long long int max=LONG_MIN;
long long int n,m;


int check(int i,int j)
{
	if(i==0 && j==0)
		return 0;
	else if((i==0 && j!=0))
	{
		if(a[i][j-1]<0)
			return 0;
		return 1;
	}
	else if((i!=0 && j==0))
		return 2;
	else if((a[i][j]+a[i-1][j])>(a[i][j]+a[i][j-1]))
		return 2;
	else
		return 1;
	return 0;
}

int main()
{
	long long int T;
	scanf("%lld",&T);
	while(T--)
	{
		max=LONG_MIN;
		scanf("%lld %lld",&n,&m);
		long long int i,j;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				scanf("%lld",&a[i][j]);
				if(check(i,j)==1)
					a[i][j] += a[i][j-1];
				else if(check(i,j)==2)
					a[i][j] += a[i-1][j];
			}
		}
		for(i=0;i<m;i++)
			max = a[n-1][i]>max?a[n-1][i]:max;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
				printf("%lld ",a[i][j]);
			printf("\n");
		}
		if(max<0)
			printf("0\n");
		else
			printf("%lld\n",max);
	}
	return 0;
}
