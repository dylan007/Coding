#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define mod 10000007

unsigned long long int mul[3][3];

unsigned long long int z[3][3];

unsigned long long int ans[3][3];

void multiply(unsigned long long int f)
{
	unsigned long long int i,j,k,sum=0;
	if(f==1)
	{
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				sum=0;
				for(k=0;k<3;k++)
					sum += ((mul[i][k] % mod)*(mul[k][j] % mod))%mod;
				ans[i][j] = sum;
			}
		}
	}
	else if(f==2)
	{
		for (i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				sum=0;
				for(k=0;k<3;k++)
					sum += ((mul[i][k] % mod)*(z[k][j] % mod))%mod;
				ans[i][j] = sum;
			}
		}
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			mul[i][j] = ans[i][j];
	}

}

void power(unsigned long long int n)
{
	if( n == 0 || n == 1)
		return;
	power(n/2);
	multiply(1);
	if (n%2 != 0)
		multiply(2);
}


int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		unsigned long long int n,a,b,c,d,e,f;
		scanf("%llu %llu %llu %llu %llu %llu %llu",&n,&a,&b,&c,&d,&e,&f);
		unsigned long long int i,j;
		n--;
		mul[0][0] = z[0][0] = a;
		mul[0][1] = z[0][1] = b;
		mul[0][2] = z[0][2] = c;
		mul[1][0] = 1;
		mul[2][1] = 1;
		mul[1][1] = 0;
		mul[1][2] = 0;
		mul[2][0] = 0;
		mul[2][2] = 0;
		z[1][0] = z[2][1] = 1;
		z[1][1] = z[1][2] = z[2][0] = z[2][2] = 0;
		/*for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
				printf("%llu ",z[i][j]);
			printf("\n");
		}
		printf("\n");
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
				printf("%llu ",mul[i][j]);
			printf("\n");
		}
		printf("\n");
		*/
		switch(n)
		{
			case 0:
				printf("%llu\n",d);
				break;
			case 1:
				printf("%llu\n",e);
				break;
			case 2:
				printf("%llu\n",f);
				break;
			default:
				power(n-2);	
				printf("%llu\n",((f*ans[0][0] + e*ans[0][1] + d*ans[0][2])%mod));
				break;
		}
	}
	return 0;
}
