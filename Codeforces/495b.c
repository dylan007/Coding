#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	int i,count=0;
	if(a==b)
		printf("infinity\n");
	else
	{
		for(i=1;i*i<=(a-b);i++)
		{
			if((a-b)%i == 0)
			{
				if(i>b)
					count++;
				if((a-b)/i>b && (a-b)/i!=i)
					count++;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
