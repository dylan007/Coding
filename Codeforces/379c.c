#include<stdio.h>
#include<stdlib.h>

int cmpfunc(const void *a,const void *b)
{
	return *(int *)a - *(int *)b;
}

int foo(int a[],int start,int finish,int x)
{
	int i,c=0;
	for(i=start;i<finish;i++)
	{
		if(a[i] == x)
			c++;
		else
			return c;
	}
	return c;
}

int main()
{
	int n,i,j,t;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	qsort(a,n,sizeof(int),cmpfunc);
	for(i=0;i<n;i++)
	{
		t = foo(a,i+1,n,a[i]);
		if(t == 0)
			printf("%d ",a[i]);
		else
		{
			for(j=i;j<i+t;j++)
				printf("%d ",a[i]+j-i);
			i = i+t;
		}
	}
	return 0;
}
