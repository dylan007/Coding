#include<stdio.h>
#include<stdlib.h>
#define NL printf("\n");

int cmpfunc(const void *a,const void *b)
{
	return *(int *)b - *(int *)a;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int i,N,K,sum=0,c1=0,c2=0;
		scanf("%d %d",&N,&K);
		int a[N];
		for(i=0;i<N;i++)
		{
			scanf("%d",&a[i]);
			sum += a[i];
		}
		qsort(a,N,sizeof(int),cmpfunc);
		for(i=(N-K);i<N;i++)
			c1 += a[i];
		for(i=0;i<K;i++)
			c2 += a[i];
		int c3,c4;
		c3 = sum - c1;
		c4 = sum - c2;
		c3 = abs(c3 - c1);
		c4 = abs(c4 - c2);
		c3>c4?printf("%d",c3):printf("%d",c4);
		NL;
	}
	return 0;
}
