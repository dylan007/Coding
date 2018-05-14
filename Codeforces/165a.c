#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,i,f1,f2,f3,f4;
	scanf("%d",&n);
	int x[n],y[n],j,count=0;
	for(i=0;i<n;i++)
		scanf("%d %d",&x[i],&y[i]);
	for(i=0;i<n;i++)
	{
		f1 = f2 = f3 = f4 = 0;
		for(j=0;j<n;j++)
		{
			if(i != j)
			{
				if(x[i] == x[j])
				{
					if(y[i]>y[j]) 				//lower neighbor
						f3 = 1;
					else if(y[i]<y[j])
						f4 = 1;				//upper neighbor			
				}
				else if(y[i] == y[j])
				{
					if(x[i] > x[j])
						f1 = 1;				//right
					else if(x[i]<x[j])
						f2 = 1;				//left
				}
			}
		}
		if((f1 == 1)&&(f2 == 1)&&(f3 == 1)&&(f4 == 1))
			count++;
	}
	printf("%d\n",count);
	return 0;
}
