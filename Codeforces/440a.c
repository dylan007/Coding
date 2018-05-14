#include<stdio.h>
#include<stdlib.h>

int cmpfunc(const void *a,const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int n,i;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<(n-1);i++)
		scanf("%d",&a[i]);
	qsort(a,n,sizeof(int),cmpfunc);
	for(i=0;i<(n-1);i++)
	{
		if(a[i] != i+1)
		{
			printf("%d\n",i+1);
			return 0;
		}
	}
	printf("%d\n",n);
	return 0;
}
