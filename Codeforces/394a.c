#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	char inp[400];
	scanf("%s",inp);
	int x=0,y=0,z=0;
	int i,len,state=1;
	len = strlen(inp);
	for(i=0;i<len;i++)
	{
		if(inp[i]=='+')
			state=2;
		else if(inp[i]=='=')
			state=3;
		else if(state==1)
			x++;
		else if(state==2)
			y++;
		else if(state==3)
			z++;
	}
	int max=0;
	max = x>y?x:y;
	if(max!=x)
	{
		y = x;
		x = max;
	}
	if(x+y == z)
		printf("%s\n",inp);
	else if(x+y == z+2)
	{
		for(i=0;i<(x-1);i++)
			printf("|");
		printf("+");
		for(i=0;i<y;i++)
			printf("|");
		printf("=");
		for(i=0;i<=z;i++)
			printf("|");
		printf("\n");
	}
	else if(x+y+2 == z)
	{
		for(i=0;i<=x;i++)
			printf("|");
		printf("+");
		for(i=0;i<y;i++)
			printf("|");
		printf("=");
		for(i=0;i<(z-1);i++)
			printf("|");
		printf("\n");
	}
	else
		printf("Impossible\n");
	return 0;
}
