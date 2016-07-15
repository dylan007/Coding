#include<stdio.h>
#include<stdlib.h>

int main()
{
	int m,i,x,y;
	scanf("%d",&m);
	int c[m],sum=0,tot=0;
	for(i=0;i<m;i++)
	{
		scanf("%d",&c[i]);
		sum += c[i];
	}
	scanf("%d %d",&x,&y);
	for(i=0;i<m;i++)
	{
		tot += c[i];
		if((tot >= x)&&(tot <= y)&&(sum-tot >= x)&&(sum-tot <= y))
		{
			printf("%d\n",i+2);
			return 0;
		}
	}
	printf("0\n");
	return 0;
}
