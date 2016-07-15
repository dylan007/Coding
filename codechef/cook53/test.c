#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>

#define MOD 10000007

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int i,j,x,temp=1;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&x);
			temp = (temp*x)%MOD;
		}
	}
	printf("%d\n",temp);
	return 0;
}
