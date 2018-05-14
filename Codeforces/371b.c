#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int check(int x)
{
	if(x%2!=0 && x%3!=0 && x%5!=0)
		return 0;
	return 1;
}

int gcd(int a,int b)
{
	return (a==0)?b:gcd(b%a,a);
}

int main()
{
	int x,y;
	scanf("%d %d",&x,&y);
	int count=0,t,f=0;
	t = gcd(x,y);
	x/=t;
	y/=t;
	while(x>1)
	{
		if(x%2!=0 && x%3!=0 && x%5!=0)
		{
			f=1;
			break;
		}
		if(x%2 == 0)
			x/=2;
		else if(x%3 == 0)
			x/=3;
		else if(x%5 == 0)
			x/=5;
		count++;
	}
	while(y>1)
	{
		if(y%2!=0 && y%3!=0 && y%5!=0)
		{
			f=2;
			break;
		}
		if(y%2 == 0)
			y/=2;
		else if(y%3 == 0)
			y/=3;
		else if(y%5 == 0)
			y/=5;
		count++;
	}
	if(f>0)
		printf("-1\n");
	else
		printf("%d\n",count);
	return 0;
}
