#include<stdio.h>
#include<stdlib.h>
int main()
{
	long int i,t,l,s,d,c;
	scanf("%ld",&t);
	loop : for(i=0;i<t;i++)
	{
		scanf("%ld %ld %ld %ld",&l,&d,&s,&c);
		if(d==1)
		{
			if(s>=l)
				printf("ALIVE AND KICKING\n");
			else
				printf("DEAD AND ROTTING\n");
		}
		else
		{
			int count=s,j;
			for(j=1;j<d;j++)
			{
				count=count+(count*c);
				if(count>=l)
				{
					printf("ALIVE AND ROTTING\n");
					goto loop;
				}
			}
			if(count<l)
				printf("DEAD AND ROTTING\n");
		}
	}
	return 0;
}
