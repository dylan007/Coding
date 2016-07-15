#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i,n,d;
	scanf("%d %d",&n,&d);
	int a[n],sum=0;
	if(d <= 10*(n-1))
	{
		printf("-1\n");
		return 0;
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		sum += a[i];

	}
	if(d < 10*(n-1) + sum)
	{
		printf("-1\n");
		return 0;
	}
	d -= 10*(n-1)+sum;
	d /= 5;
	d += 2*(n-1);
	printf("%d\n",d);

	return 0;
}
