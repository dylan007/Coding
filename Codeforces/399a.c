#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char s[100];
	scanf("%s",s);
	int len,i,c1=0,c2=0,c3=0;
	len = strlen(s);
	for(i=0;i<len;i += 2)
	{
		switch(s[i])
		{
			case '1':
				c1++;
				break;
			case '2':
				c2++;
				break;
			case '3':
				c3++;
				break;
		}	
	}
	for(i=0;i<len;i++)
	{
		if(i%2 != 0)
			printf("+");
		else
		{
			if(c1 != 0)
			{
				printf("1");
				c1--;
			}
			else if(c2 != 0)
			{
				printf("2");
				c2--;
			}
			else if(c3 != 0)
			{
				printf("3");
				c3--;
			}
		}
	}
	printf("\n");
	return 0;
}
