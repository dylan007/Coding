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

int pop(stack *s)
{
	if(s->top < 0)
		return -1;
	return s->arr[s->top--];
}

int eval(char op,int x,int y)
{
	if(op=='+')
		return x+y;
	if(op=='-')
		return x-y;
	if(op=='*')
		return x*y;
	return x/y;
}

int isdig(char x)
{
	if(x>'0' && x<'9')
		return (int)x-(int)'0';
	return -1;
}

int main()
{
	char p[50];
	scanf("%s",p);
	int l = strlen(p);
	int i;
	stack s;
	s.top = -1;
	for(i=l-1;i>=0;i--)
	{
		if(isdig(p[i])>=0)
			push(&s,isdig(p[i]));
		else
		{
			int x,y;
			x = pop(&s);
			y = pop(&s);
			push(&s,eval(p[i],x,y));
		}
	}
	printf("%d\n",pop(&s));
	return 0;
}
