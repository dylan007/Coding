#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int arr[100];
	int top;
}stack;

void push(stack *a,int x)
{
	a->top ++;
	a->arr[a->top] = x;
	return;
}

int pop(stack *a)
{
	if(a->top == -1)
		return -1;
	a->top --;
	return 1;
}


int main()
{
	stack a;
	a.top = -1;
	char c;
	int flag=0;
	scanf("%c",&c);
	while(c != '\n')
	{
		if(c=='(')
			push(&a,1);
		else if(c==')')
		{
			if(pop(&a)<0)
			{
				flag=1;
				break;
			}
		}
		scanf("%c",&c);
	}
	if(a.top >= 0)
		flag=1;
	if(flag)
		printf("Invalid expression\n");
	else
		printf("Valid expression\n");
	return 0;
}