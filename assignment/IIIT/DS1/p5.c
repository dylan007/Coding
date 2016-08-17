#include<stdio.h>
#include<stdlib.h>

int cmpfunc(const void *a,const void *b)
{
	return *(long long int *)a - *(long long int *)b;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int i,j;
		long long int n,k;
		scanf("%lld %lld",&n,&k);
		char inp[1000000];
		long long int a[n];
		for(i=0;i<n;i++)
			scanf("%*C%s%*C%lld",inp,&a[i]);
		qsort(a,n,sizeof(long long int),cmpfunc);
		long long int f=0,t;
		for(i=0;i<(n-2);i++)
		{
			j = i+1;
			t=n-1;
			while(t>j)
			{
				if(a[i]+a[j]+a[t]==k)
				{
					f=1;
					break;
				}
				else
					(a[i]+a[j]+a[t]>k) ? t--:j++;
			}
			if(f==1)
				break;
		}
		if(f==1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
