#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int c1=0;
int c2=0;
int flag=0;
void game(int n)
{
	if(n==0)
	{
		c1 += flag;
		c2 += !flag;
	}
	else
	{
		flag=(flag==0)?1:0;
		if(n>=2)
			game(n-2);
		game(n-1);
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		c1=0;
		c2=0;
		int n,k;
		scanf("%d %d",&n,&k);
		flag=k-1;
		game(n);
		printf("%d %d\n",c1,c2);
	}
	return 0;
}
