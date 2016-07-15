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
		int n;
		scanf("%d",&n);
		int a[n],i;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		qsort(a,n,sizeof(int),cmpfunc);
		int temp=-1;
		int count=0;
		for(i=0;i<n;i++)
		{
			if(temp!=a[i])
			{
				count++;
				temp = a[i];
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
