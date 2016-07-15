#include<stdio.h>
#include<stdlib.h>

int cmpfunc(const void *a,const void *b)
{
	return *(int *)a - *(int *)b;
}

int count(int a[],int x,int n)
{
	int i,c=0;
	for(i=0;i<n;i++)
	{
		c += (a[i] == x);
		if(a[i]>x)
			return c;
	}
	return c;
}

int factorial(int x)
{
	if(x==1) return 1;
	return x*factorial(x-1);
}

int main()
{
	int T;
	scanf("%d",&T);	
	while(T--)
	{
		int x,i,score[11],k,sum,min;
		for(i=0;i<11;i++) scanf("%d",&score[i]);
		qsort(score,11,sizeof(int),cmpfunc);
		scanf("%d",&k);
		min = score[10];
		sum = 0;
		for(i=10;i>(10-k);i--)
		{
			sum += score[i];
			if(min>score[i])
			{
				min = score[i];
				x = i;
			}
		}
		x = x-(10-k);
		min = count(score,score[10-k],11);
		printf("%d\n",((factorial(min))/(factorial(min-x)*factorial(x))));
	}
	return 0;
}
