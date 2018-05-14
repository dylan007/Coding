#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int cmpfunc(const void *a, const void *b)
{
	return *(long long int *)a - *(long long int *)b;
}

int main()
{
	long long int n;
	scanf("%I64d",&n);
	long long int a[n];
	long long int i;
	for(i=0;i<n;i++)
		scanf("%I64d",&a[i]);
	qsort(a,n,sizeof(long long int),cmpfunc);
	long long int min=1,max=1;
	for(i=1;i<n;i++)
	{
		if(a[i]==a[0])
			min++;
		else 
			break;
	}
	for(i=n-2;i>=0;i--)
	{
		if(a[i]==a[n-1])
			max++;
		else
			break;
	}
	if(a[0]==a[n-1])
		printf("0 %I64d\n",(n*(n-1))/2);
	else
		printf("%I64d %I64d\n",a[n-1]-a[0],min*max);
	return 0;
}
