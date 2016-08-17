#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int cmpfunc(const void *a,const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int i,n;
		scanf("%d",&n);
		int a[n];
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		int x,sum=0;	
		int max=0;
		int f=0,MAX=-2000000000;
		for(i=0;i<n;i++)
		{
			sum+=a[i];
			if(a[i]>=0)
				f=1;
			MAX=MAX<a[i]?a[i]:MAX;
			if(sum<0)
				sum=0;
			else if(max<sum)
				max = sum;
		}
		if(f==1)
			printf("%d ",max);
		else
			printf("%d ",MAX);
		qsort(a,n,sizeof(int),cmpfunc);
		if(f==0)
			printf("%d\n",a[n-1]);
		else
		{
			sum=0;
			for(i=(n-1);i>=0;i--)
			{
				if(a[i]<0)
					break;
				sum+=a[i];
			}
			printf("%d\n",sum);
		}
	}
	return 0;
}
