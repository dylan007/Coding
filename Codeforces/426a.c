#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>

int main()
{
	int n,s,x,sum=0,max=INT_MIN;
	scanf("%d %d",&n,&s);
	while(n--)
	{
		scanf("%d",&x);
		sum+=x;
		max=(max>x)?max:x;
	}
	if(sum-max <= s)
		printf("YES\n");
	else
		printf("NO\n");
}
