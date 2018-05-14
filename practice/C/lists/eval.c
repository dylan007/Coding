#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char str[100];
	scanf("%s",str);
	//evaluation
	char stack[100];
	int top=49;
	int i,j;
	for(i=0;i<strlen(str);i++)
	{
//		for(j=top-1;j>=49;j--)
//			printf("%c ",stack[j]);
//		printf("\n");
		if(str[i]=='(')
			continue;
		else if((str[i]>='0' && str[i]<='9')||(str[i]=='*' || str[i]=='+' || str[i]=='-' || str[i]=='/'))
			stack[top++] = str[i];
		else if(str[i]==')')
		{
			int x,y;
			y = (int)(stack[top-1]-'0');
			x = (int)(stack[top-3]-'0');
			//printf("%d %d\n",x,y);
			switch(stack[top-2])
			{
				case '*':
					x *= y;
					break;
				case '+':
					x += y;
					break;
				case '-':
					x -= y;
					break;
				case '/':
					x /=y;
					break;
			}
			top -= 3;
			stack[top++] = (char)(x+48);
			//printf("stack %c",stack[top-1]);
		}
	}
//	for(j=top-1;j>=49;j--)
//		printf("%c ",stack[j]);
	printf("%c\n",stack[top-1]);
	return 0;
}
