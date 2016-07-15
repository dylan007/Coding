#include<stdio.h>
#include<string.h>
#include<string.h>
#include<math.h>

int cmpfunc(const void *a,const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int n,m,k,i,j,x;
	scanf("%d %d %d",&n,&m,&k);
	int a[500000];
	int top=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			x = i*j;
			a[top++] = x;
		}
	}
	qsort(a,top,sizeof(int),cmpfunc);
	printf("%d\n",a[k-1]);
	return 0;
}
