#include<stdio.h>
#include<stdlib.h>

int cmpfunc(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int N,D,i=0;
	scanf("%d %d",&N,&D);
	int a[N];
	while(i<N)
	{
		scanf("%d",&a[i]);
		i++;
	}
	qsort(a,N,sizeof(int),cmpfunc);
	int count=0;
	for(i=0;i<N-1;i++)
	{
		if(a[i+1]-a[i] <= D)
		{
			count++;
			i = i+1;
		}
	}
	printf("%d\n",count);
	return 0;
}
