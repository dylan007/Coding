#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	int T;
	scanf("%d%*C",&T);
	while(T--)
	{
		char table[15];
		scanf("%s",table);
		int i,count=0,j=0,k,f=0;
		for(i=1;i<=12;i++)
		{
			if(12%i == 0)
			{
				f=0;
				for(j=1;j<=(12/i);j++)
				{
					f=0;
					for(k=(j);k<=12;k+=(12/i))
					{
						if(table[k-1]=='O')
						{
							f=1;
							break;
						}
					}
					if(f==0)
						break;
				}
				if(f==0)
					count++;
			}
		}
		printf("%d ",count);
		for(i=1;i<=12;i++)
		{
			if(12%i == 0)
			{
				f=0;
				for(j=1;j<=(12/i);j++)
				{
					f=0;
					for(k=(j);k<=12;k+=(12/i))
					{
						if(table[k-1]=='O')
						{
							f=1;
							break;
						}
					}
					if(f==0)
						break;
				}
				if(f==0)
					printf("%dx%d ",i,12/i);
			}
		}
		printf("\n");
	}
	return 0;
}
