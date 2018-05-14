#include<stdio.h>
#include<stdlib.h>

int cmpfunc(const void *a,const void *b)
{	
	return *(int *)a - *(int *)b;
}

int main()
{
	int i,n,m,v;
	scanf("%d%d",&n,&m);
	int a[n],b[m];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<m;i++)
		scanf("%d",&b[i]);
	qsort(a,n,sizeof(int),cmpfunc);
	qsort(b,m,sizeof(int),cmpfunc);
	if(a[n-1] >= b[0])
	{
		printf("-1\n");
		return 0;
	}

	if(b[0] <= 2*a[0])
	{
		printf("-1\n");
		return 0;
	}

	if(a[n-1] >= 2*a[0])
	{
		printf("%d\n",a[n-1]);
		return 0;
	}
	else
		printf("%d\n",2*a[0]);
	return 0;
}
