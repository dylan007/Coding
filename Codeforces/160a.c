#include<stdio.h>
#include<stdlib.h>

int cmpfunc(const void *a, const void *b)
{
	return *(int *)b - *(int *)a;
}

int main()
{
	int n,i,sum1=0,sum2=0,count=0;
	scanf("%d",&n);
	int coin[n];
	for(i=0;i<n;i++){
		scanf("%d",&coin[i]);
		sum2 += coin[i];
	}
	qsort(coin,n,sizeof(int),cmpfunc);
	i=0;
	while((sum1<=sum2)&&(i<n))
	{
		sum1 += coin[i];
		sum2 -= coin[i];
		i++;
		count++;
		//printf("%d %d %d %d\n",i,sum1,sum2,count);
	}
	printf("%d\n",count);
	return 0;
}
