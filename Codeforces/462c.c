#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int cmpfunc(const void *a,const void *b)
{
	return *(long long int *)a - *(long long int *)b;
}

int main()
{
	long long int n;
	scanf("%I64d",&n);
	long long int a[n];
	long long int i,sum=0,ans;
	for(i=0;i<n;i++)
	{
		scanf("%I64d",&a[i]);
		sum += a[i];
	}
	qsort(a,n,sizeof(long long int),cmpfunc);
	ans = sum;
	for(i=0;i<(n-1);++i)
	{
		ans += sum;
		sum -= a[i];
	}
	printf("%I64d\n",ans);
	return 0;
}
