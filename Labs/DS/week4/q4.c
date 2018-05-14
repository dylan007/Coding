#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int val[100];
	int top;
}stack;

void push(stack *a,int x)
{
	a->top ++;
	a->val[a->top] = x;
	return;
}

int pop(stack *a)
{
	if(a->top == -1)
		return -1;
	a->top --;
	return a->val[a->top + 1];
}

int main()
{
	int x;
	scanf("%d",&x);
	stack a;
	a.top = -1;
	while(x>0)
	{
		push(&a,x%2);
		x >>= 1;
	}
	while(1)
	{
		x = pop(&a);
		if(x>=0)
			printf("%d",x);
		else
		{
			printf("\n");
			break;
		}
	}
	return 0;
}