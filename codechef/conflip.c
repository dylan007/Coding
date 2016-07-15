#include<stdio.h>
#include<stdlib.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int G;
		scanf("%d",&G);
		while(G--)
		{
			long long int c=0,i,N,I,Q;
			scanf("%lld %lld %lld",&I,&N,&Q);
			if(N%2 == 0) printf("%lld\n",N/2);
			else printf("%lld\n",N/2 + !(I==Q));
		}
	}	
	return 0;
}
