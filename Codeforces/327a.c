#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,i,max=0,sum=0,c1=0,l2=0,l1=0;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		c1 += a[i];
	}
	if(c1 == n)
	{
		printf("%d\n", n-1);
		return 0;
	}
	else if(c1==0)
	{
		printf("%d\n",n);
		return 0;
	}
	int j,k,temp;
	for(i=0;i<(n-1);i++)
	{
		for(j=i;j<n;j++)
		{
			temp = 0;
			for(k=0;k<n;k++)
			{
				if(!(k>=i && k<=j))
					temp+=(a[k]==1);
				else
					temp+=(a[k]==0);
			}
			max = max<temp?temp:max;
		}
	}
	printf("%d\n",max);
	return 0;
}
