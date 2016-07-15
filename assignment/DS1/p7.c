#include<stdio.h>
#include<stdlib.h>

int cmpfunc(const void *a,const void *b)
{
	return *(long long int *)a - *(long long int *)b;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int n;
		scanf("%lld",&n);
		long long int a[n];
		long long int i;
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		qsort(a,n,sizeof(long long int),cmpfunc);
		long long int count=0;
		long long int temp=a[0];
		long long int C=1;
		for(i=1;i<n;i++)
		{
			if(temp!=a[i])
			{
				count += (C*(C-1))/2;
				C = 1;
				temp = a[i];
			}
			else
				C++;
		}
		count += ((C-1)*C)/2;
		printf("%lld\n",count);
	}
}
