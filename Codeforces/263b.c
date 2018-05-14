#include<stdio.h>
#include<stdlib.h>

int cmpfunc(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int i,n,k,x=0,y=0;
	scanf("%d %d",&n,&k);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	qsort(a,n,sizeof(int),cmpfunc);
	if(k>n)
	{
		printf("-1\n");
		return 0;
	}
	else
	{
		x = a[n-k];
		printf("%d %d\n",x,y);
	}
	return 0;
}
