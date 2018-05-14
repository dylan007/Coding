#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b)
{
	return *(long long int *)a - *(long long int *)b;
}

int main()
{
	long long int n,x,i,p;
	long long int t=0;
	scanf("%I64d %I64d",&n,&x);
	long long int a[n];
	for(i=0;i<n;i++)
		scanf("%I64d",&a[i]);
	qsort(a,n,sizeof(long long int),cmp);
	for(i=0;i<n;i++)
	{
		t += x*a[i];
		x -= (x>1);
	}
	printf("%I64d\n",t);
	return 0;
}
