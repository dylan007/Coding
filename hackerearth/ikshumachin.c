#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int cmpfunc(const void *a,const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int T;
	scanf("%d",&T);
	int a[T],b[T];
	int i=0,k;
	k=T;
	while(k--)
	{
		int x;
		scanf("%d",&x);
		a[i]=x;
		b[i]=x;
		i++;
	}
	int count=0;
	int j=0;
	for(i=0;i<T;i++)
	{
		for(j=0;j<T;j++)
		{
			if(a[i]<a[j])
				b[j] -= 1;
		}
		printf("%d ",b[i]);
	}
	printf("\n");
	return 0;
}
