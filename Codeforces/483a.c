#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

unsigned long long int gcd(unsigned long long int a,unsigned long long int b)
{
	return (a==0)?b:gcd(b%a,a);
}

int main()
{
	unsigned long long int i,j,k,l,r;
	scanf("%llu %llu",&l,&r);
	for(i=l;i<=r;i++)
	{
		for(j=i+1;j<=r;j++)
		{
			for(k=j+1;k<=r;k++)
			{
				if((gcd(i,j)==1) && (gcd(j,k)==1) && (gcd(i,k)!=1))
				{
					printf("%llu %llu %llu\n",i,j,k);
					return 0;
				}
			}
		}
	}
	printf("-1\n");
	return 0;
}
