#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i,j,n,m,count=0;
	scanf("%d %d",&n,&m);
	if(n>m)
	{
		i = n;
		n = m;
		m = i;
	}
	for(i=0;;i++)
	{
		j = n - i*i;
		if(j<0)
			break;
		if(j*j == (m - i))
			count++;
	}
	printf("%d\n",count);
	return 0;
}
