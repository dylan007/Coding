#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int p,q,r;
		scanf("%lld",&p);
		long long int A[p];
		long long int i=0;
		for(i=0;i<p;i++)
			scanf("%lld",&A[i]);
		scanf("%lld",&q);
		long long int B[q];
		for(i=0;i<q;i++)
			scanf("%lld",&B[i]);
		scanf("%lld",&r);
		long long int C[r];
		for(i=0;i<r;i++)
			scanf("%lld",&C[i]);
		long long int count=0;
		long long int j,k,ans,t;
		i=j=t=0;
		while((i<p) && (j<q) && (t<r))
		{
			while(i<p && i<=j && A[i]<=B[j])
				i++;
			while(t<r && (t<j || C[t]<B[j]))
				t++;
			count += i*(r-t);
			j++;
		}
		printf("%lld\n",count);
	}
	return 0;
}
