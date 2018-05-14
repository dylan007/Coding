#include<stdio.h>
#include<stdlib.h>

int cmpfunc(const void *a, const void *b) {return *(int *)a - *(int *)b;}

int main()
{
	int n,i;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	qsort(a,n,sizeof(int),cmpfunc);
	i = a[0];
	a[0] = a[n-1];
	a[n-1] = i;
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
