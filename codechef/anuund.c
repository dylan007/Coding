#include<stdio.h>
#include<stdlib.h>

int cmpi(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int cmpd(const void *a,const void *b)
{
	return *(int *)b - *(int *)a;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,i;
		scanf("%d",&n);
		int a[n],dec[n],inc[n];
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			dec[i] = a[i];
			inc[i] = a[i];
		}
		qsort(inc,n,sizeof(int),cmpi);
		int top=n-1;
		int bot=0;
		while(bot<top)
		{
			if(bot!=top)
			{
				printf("%d %d ",inc[bot],inc[top]);
				bot++;
				top--;
			}
		}
		if(n%2 == 1)
			printf("%d",inc[(n-1)/2]);		
		printf("\n");
	}
	return 0;
}
