#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		char inp[100010];
		scanf("%s",inp);
		char a[4] = {'0','1','0','\0'};
		char b[4] = {'1','0','1','\0'};
		if(strstr(inp,a)!=NULL)
			printf("Good\n");
		else if(strstr(inp,b)!=NULL)
			printf("Good\n");
		else
			printf("Bad\n");
	}
	return 0;
}
