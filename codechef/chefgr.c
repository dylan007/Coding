#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int cmpfunc(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int N,M;
		scanf("%d %d",&N,&M);
		int a[N];
		int i;
		for(i=0;i<N;i++)
			scanf("%d",&a[i]);
		qsort(a,N,sizeof(int),cmpfunc);
		int sum=0;
		for(i=0;i<N-1;i++)
			sum+=a[N-1]-a[i];
		if(sum==M)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
