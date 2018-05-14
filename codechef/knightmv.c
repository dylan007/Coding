#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int T;
	scanf("%d%*C",&T);
	while(T--)
	{
		char c,inp[11];
		int i=0,len;
		while((c=getchar())!='\n')
		{
			inp[i] = c;
			i++;
		}
		len = i;
		if((len!=5)||(inp[2]!='-'))
		{
			printf("Error\n");
			continue;
		}
		int t,s;
		t = inp[0];
		if(!(t>=97 && t<=104))
		{
			printf("Error\n");
			continue;
		}
		t = inp[3];
		if(!(t>=97 && t<=104))
		{
			printf("Error\n");
			continue;
		}
		s = inp[1] - '0';
		t = inp[4] - '0';
		if((!(t>=1 && t<=8))||(!(s>=1 && s<=8)))
		{
			printf("Error\n");
			continue;
		}
		s = abs(inp[0]-inp[3]);
		t = abs(inp[1]-inp[4]);
		if((s==1 && t==2)||(s==2 && t==1))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
