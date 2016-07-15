#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		char exp[405],stack[405],out[405];
		int i,s=0,p=0;
		scanf("%s",exp);
		for(i=0;exp[i];i++)
		{
			if((exp[i]=='(')||(exp[i]=='+')||(exp[i]=='-')||(exp[i]=='*')||(exp[i]=='/')||(exp[i]=='^'))
			{
				stack[s++] = exp[i];
				stack[s] = '\0';
			}
			else if(exp[i]==')')
			{
				out[p++] = stack[s-1];
				s-=2;
			}
			else
				out[p++] = exp[i];
		}
		out[p] = '\0';
		printf("%s\n",out);
	}
	return 0;
}
