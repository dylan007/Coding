#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,k,i,j,t,null,count=0,flag=0;
	scanf("%d",&n);
	k = 2*n +1;
	for(i=0;i<k;i++)
	{
		count=0;
//		flag=0;
		if(i<=n)
			t = 2*i + 1;
		else
			t = 2*(k-i-1) + 1;
		null = k-t;
		null = null/2;
		for(j=0;j<k;j++)
		{
			if(j<null)
				printf("  ");
			else if((j>=null)&&(j<(null+(t-1)/2)))
			{
				printf("%d ",count);
				count++;
			}
			else if((j>=(null+(t-1)/2))&&(j<(null-1+t)))
			{
				printf("%d ",count);
				count--;
			}
			//printf("%d",count);
		}
		printf("%d\n",count);
	}
	return 0;
}
