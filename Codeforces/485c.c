#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>

/*unsigned long long int countBits(unsigned long long int x)
{
	unsigned long long int count=0;
	while(x)
	{
		x &= (x-1);
		count++;
	}
	return count;
}*/

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int x,l,r,i,max=0,ans=0;
		scanf("%lld %lld",&l,&r);
		x = 1;
		for(i=0;i<64;i++)
		{
			ans = l|x;
			if(ans > r)
				break;
			l = ans;
			x<<=1;
		}
		printf("%lld\n",l);
	}
	return 0;
}
