#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int i,n,a,b,c1=0,c2=0;
		scanf("%d %d %d",&n,&a,&b);
		int blah[n],sum=0;
		for(i=0;i<n;i++)
		{
			c1 += a%2;
			a /= 2;
			blah[i] = 1;
		}
		for(i=0;i<n;i++)
		{
			c2 += b%2;
			b /= 2;
		}
		c1 = abs(c1+c2-n);
		for(i=0;i<c1;i++) blah[i] = 0;
		for(i=0;i<n;i++) sum += pow(2,i)*blah[i];
		printf("%d\n",sum);
	}
	return 0;
}
