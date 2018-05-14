#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int T;
	char dict[30];
	scanf("%d%*C%s",&T,dict);
	while(T--)
	{
		char inp[103];
		scanf("%s%*C",inp);
		int len,i,t;
		len = strlen(inp);
		for(i=0;i<len;i++)
		{
			t = inp[i];
			if(t == 95) printf(" ");
			else if((t>=97)&&(t<=122)) printf("%c",dict[t-97]);
			else if((t>=65)&&(t<=90)) 
			{
				t -= 65;
				printf("%c",dict[t]-32);	
			}
			else
				printf("%c",inp[i]);
		}
		printf("\n");
	}
	return 0;
}
