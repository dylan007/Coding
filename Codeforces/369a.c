#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,m,k,x,i,count=0;
	scanf("%d %d %d",&n,&m,&k);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		if(x == 1)
		{
			if(m > 0)
				m--;
			else
				count++;
		}
		else if(x == 2)
		{
			if((m != 0) && (k != 0))
				k--;
			else if((m != 0)&&(k == 0))
				m--;
			else if((m == 0) && (k != 0))
				k--;
			else
				count++;
		}
	}	
	printf("%d\n",count);
	return 0;
}
