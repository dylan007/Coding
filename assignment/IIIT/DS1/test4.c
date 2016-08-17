#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int p;
		scanf("%d",&p);
		int a[p];
		int i;
		for(i=0;i<p;i++)
			scanf("%d",&a[i]);
		int q,r;
		scanf("%d",&q);
		int b[q];
		for(i=0;i<q;i++)
			scanf("%d",&b[i]);
		scanf("%d",&r);
		int c[i];
		for(i=0;i<r;i++)
			scanf("%d",&c[i]);
		int dp1[q],dp2[r];
		int j=0,temp=0;
		i=0;
		while(i<q)
		{
			if(b[i]<a[j])
				
		}
		temp = 0;
		for(i=0;i<r;i++)
		{
			for(j=temp;j<q;j++)
			{
				if(b[i]>c[j])
					break;
			}
			dp2[i] = (j>i)?i:j;
			temp = j;
		}
		temp = (q>r)?q:r;
		int count=0;
		for(i=0;i<q;i++)
			printf("%d ",dp1[i]);
		for(i=0;i<r;i++)
			printf("%d ",dp2[i]);
		for(i=0;i<temp;i++)
			count += dp1[i]*dp2[i];
		printf("%d\n",count);
	}
	return 0;
}
