#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,m,k,i;
	scanf("%d %d",&n,&m);
	int b[n],li[n];
	for(i=0;i<m;i++)
		scanf("%d",&b[i]);
	for(i=0;i<n;i++)
		li[i] = 0;
	for(i=0;i<m;i++)
	{
		for(k=(b[i]-1);k<n;k++)
		{
			if(li[k] != 0)
				break;
			li[k] = b[i];
		}
	}
	for(i=0;i<n;i++)
		printf("%d ",li[i]);
	printf("\n");
	return 0;
}
