#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

char stack[60];

void operation(long long int n,long long int index)
{
	int i;
	i = index-1;
	stack[index]='R';
	for(;i>=0;i--)
		stack[i]='B';
}

long long int check(long long int n)
{
	long long int i;
	for(i=0;i<n;i++)
	{
		if(stack[i]=='B')
			return i;
	}
	return -1;
}

int main()
{
	long long int n;
	scanf("%lld%*C",&n);
	scanf("%s",stack);
	long long int i,count=1,f=0;
	for(i=0;i<n;i++)
	{
		if(stack[i]=='B')
		{
			f=1;
			count *= (i+1);
		}
	}
	/*while(check(n)!=-1)
	{
		count++;
		operation(n,check(n));
	}*/
	printf("%lld\n",count*f);
	return 0;
}
