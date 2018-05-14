#include<stdio.h>
#include<stdlib.h>

int cmpfunc(const void *a,const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int i,c=0,n,a[3];
	scanf("%d",&n);
	for(i=0;i<3;i++)
		scanf("%d",&a[i]);
	qsort(a,3,sizeof(int),cmpfunc);
	while(n>a[2])
	{
		n -= a[0];
		c++;
	}
	printf("%d %d\n",n,c);
	return 0;
}
