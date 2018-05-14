#include<stdio.h>
#include<string.h>
#include<string.h>
#include<math.h>

int main()
{
	int x,a=0,b=0,i;
	for(i=0;i<3;i++)
	{
		scanf("%d",&x);
		a += x;
	}
	for(i=0;i<3;i++)
	{
		scanf("%d",&x);
		b += x;
	}
	int n;
	scanf("%d",&n);
	a = a/5 + (a%5 != 0);
	b = b/10 + (b%10 != 0);
	if(a+b<=n)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
