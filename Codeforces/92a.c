#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i,n,m,tot;
	scanf("%d %d",&n,&m);
	tot = (n*(n+1))/2;
	m = m%tot;
	i=1;
	while(i<=m)
	{
		m -= i;
		i++;
	}
	printf("%d\n",m);
	return 0;
}
