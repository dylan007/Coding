#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define min(a,b) (a>b)?a:b;


int gcd(int a, int b)
{
	if(a==b || b==0)
		return a;
	int c;
	c = a>b?a:b;
	b = a<b?a:b;
	a = c;
	c = gcd(b,a%b);
	return c;
}

int dict[100010];

void init()
{
	int i,j;
	for(i=0;i<100010;i++)
		dict[i] = i;
	int r;
	r = sqrt(100010);
	for(i=0;i<r+2;i++)
	{
		if(dict[i] == 1)
		{
			for(j=2*i;j<100010;j+=i)
				dict[j] = min(i,dict[j]);
		}
	}

}

int main()
{
	int T;
	init();
	scanf("%d",&T);
	while(T--)
	{
		int x,n,ans;
		scanf("%d",&n);
		scanf("%d",&x);
		n--;
		ans = x;
		while(n--)
		{
			scanf("%d",&x);
			ans = gcd(x,ans);
		}
		if(ans!=1) printf("%d\n",dict[ans]);
		else
			printf("-1\n");
	}
	return 0;
}
