#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int T;
	scanf("%d%*C",&T);
	while(T--)
	{
		char inp[320];
		getchar();
		fgets(inp,320,stdin);
		int len = strlen(inp);
		int i,a[26],b[26],t;
		for(i=0;i<60;i++){
		       	a[i] = 0;
			b[i] = 0;
		}
		for(i=0;i<len;i++)
		{
			t = inp[i];
			if(t>=65 && t<=90)
				a[t-65] = 1;
			else if(t>=97 && t<=122)
				b[t-97] = 1;
		}
		int flag=0;
		for(i=0;i<60;i++)
		{
			if(a[i]==0)
			{
				flag=1;
				printf("%c%c\n",i+'A',i+'A');
				break;
			}
		}
		if(!flag)
		{
			for(i=0;i<26;i++)
			{
				if(b[i]==0)
				{
					flag=1;
					printf("%c%c\n",i+'a',i+'a');
					break;
				}
			}
		}
		if(!flag)
			printf("~\n");
	}
	return 0;
}
