#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

typedef struct node
{
	int arr[MAX];
	int top;
}stack;

void push(stack *s,int data)
{
	s->top ++;
	s->arr[s->top] = data;
	return;
}

int pop(stack *s,int data)
{
	if(s->top == -1)
		return -1;
	return s->arr[s->top--];
}

int pr(char x)
{
	if(x==')')
		return 0;
	if(x=='+' || x=='-')
		return 1;
	if(x=='*' || x=='/')
		return 2;
	return 3;
}

void display(stack s)
{
	int i;
	for(i=0;i<s.top;i++)
		printf("%c",(char)s.arr[s.top]);
	printf("\n");
}

int isDigit(char x)
{
	return x>='0' && x<='9';
}

int main()
{
	char p[50];
	scanf("%s",p);
	char out[50];
	int i=0,l;
	l = strlen(p);
	int pos=0;
	stack s;
	s.top = -1;
	for(i=(l-1);i>=0;i--)
	{
		 if(isDigit(p[i]))
		 	out[pos++] = p[i];
		 else
		 {
		 	if(p[i] == '(')
		 	{
		 		while(s.arr[s.top]!=')')
		 			out[pos++] = s.arr[s.top--];
		 		s.top--;
		 	}
		 	else if(p[i] == ')')
				push(&s,(int)p[i]);
		 	else
		 	{
		 		while(s.top>=0 && pr(s.arr[s.top])>=pr(p[i]))
		 		{
		 			if(s.arr[s.top]=='(')
		 			{
		 				s.top -- ;
		 				continue;
		 				}
		 			if((s.arr[s.top]!='$' && pr(s.arr[s.top]==pr(p[i]))))
						break;	
					out[pos++] = s.arr[s.top--];
		 		}
		 		push(&s,(int)p[i]);
		 	}
		 }
	}		
	while(s.top>=0)
	{
		if(s.arr[s.top] != ')')
			out[pos++] = s.arr[s.top];
		s.top--;
	}
	for(i=(pos-1);i>=0;i--)
		printf("%c",out[i]);
	printf("\n");
	return 0;
}
