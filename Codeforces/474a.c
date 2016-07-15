#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main()
{
	char check[30] = "qwertyuiopasdfghjkl;zxcvbnm,./";
	char c;
	int i;
	c = getchar();
	getchar();
	if(c=='R')
	{
		while(c!='\n')
		{
			c = getchar();
			for(i=0;i<31;i++)
			{
				if(c == check[i])
					break;
			}
			if(i<31)
				printf("%c",check[i-1]);
		}
	}
	else
	{
		while(c!='\n')
		{
			c = getchar();
			for(i=0;i<31;i++)
			{
				if(c == check[i])
					break;
			}
			if(i<31)
				printf("%c",check[i+1]);
		}
	}
	printf("\n");
	return 0;
}
