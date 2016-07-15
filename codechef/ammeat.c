#include<stdio.h>
#include<stdlib.h>

int cmpfunc(const void *a , const void *b)
{
	return *(long long *)b - *(long long *)a;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long n,m,i;
		scanf("%lld %lld",&n,&m);
		long long a[n];
		for(i=0;i<n;i++) scanf("%lld",&a[i]);
		qsort(a,n,sizeof(long long),cmpfunc);
		long long sum=0,c=0;
		i=0;
		while(sum<m)
		{
			sum += a[i];
			c++;
			i++;
			if(i==n)
				break;
		}
		if(sum>=m)
			printf("%lld\n",c);
		else
			printf("-1\n");
	}
	return 0;
}
