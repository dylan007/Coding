#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct BAG
{	
	long long int sum,time,N;
}bag;

int cmpfunc(const void *a,const void *b)
{
	const struct BAG *elem1 = a;
	const struct BAG *elem2 = b;
	if(elem1->sum > elem2->sum)
		return 1;
	else if(elem1->sum < elem2->sum)
		return -1;
	else
	{
		if(elem1->time > elem2->time)
			return 1;
		else 
			return -1;
	}
}

int main()
{
	long long int n;
	scanf("%lld",&n);
	long long int mod;
	scanf("%lld",&mod);
	long long int i,m;
	bag A[n];
	long long int *cont[n];
	for(i=0;i<n;i++)
	{
		scanf("%lld",&m);
		A[i].N = m;
		A[i].time = i;
		long long int j;
		A[i].sum=0;
		cont[i] = (long long int *)malloc(m * sizeof(long long int));
		for(j=0;j<m;j++)
		{
			scanf("%lld",&cont[i][j]);
			A[i].sum = (A[i].sum+cont[i][j])%mod;
		}
	}
	qsort(A,n,sizeof(bag),cmpfunc);
	for(i=0;i<n;i++)
	{
		long long int j;
		printf("%lld\n",A[i].sum);
		for(j=0;j<A[i].N;j++)
			printf("%lld\n",cont[A[i].time][j]);
		printf("\n");
	}
	return 0;
}
