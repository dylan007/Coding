#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	int a[n];
	int i,j;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	int temp[k],c1,c2;
	for(i=0;i<k;i++)
	{
		c1=0,c2=0;
		for(j=i;j<n;j+=k)
		{
			c1+= (a[j]==1);
			c2 += (a[j]==2);
		}
		temp[i]=c1>=c2?1:2;
	}
	int ans=0;
	for(i=0;i<n;i++)
	{
		if(a[i]!=temp[i%k])
			ans++;
	}
	printf("%d\n",ans);
	return 0;
}
