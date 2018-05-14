#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>

int main()
{
	int n,m,a,b;
	int i,t;
	int min=INT_MAX;
	scanf("%d %d %d %d",&n,&m,&a,&b);
	double x,y;
	x= n;
	y= m;
	x = x/y;
	x= ceil(x);
	int temp = (int)(x);
	for(i=0;i<=temp;i++)
	{
		if(i*m <= n)
			t = a*(n-i*m) + b*i;
		else
			t = b*i;
		min = min<t?min:t;
	}
	printf("%d\n",min);
	return 0;
}
