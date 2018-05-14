#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmpfunc(const void *a,const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int n,T=1;
	scanf("%d",&n);
	while(n!=0)
	{
		int a[n];
		int i,sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		qsort(a,n,sizeof(int),cmpfunc);
		sum = sum/n;
		int count=0;
		for(i=0;i<n;i++)
		{
			if(a[i]>=sum)
				break;
			count += sum-a[i];
		}
		printf("Set #%d\nThe minimum number of moves is %d.\n",T++,count);
		scanf("%d",&n);
	}
	return 0;
}
