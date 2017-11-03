#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int val[100];
	int top;
}stack;

void insert(stack *a)
{
	int x;
	scanf("%d",&x);
	(a->top) ++;
	a->val[a->top] = x;
	return;
}

void pop(stack *a)
{
	if(a->top == -1)
		printf("Stack is empty\n");
	else
	{
		printf("%d\n",a->val[a->top]);
		a->top --;
	}
	return;
}

void disp(stack *a)
{
	int i=0;
	for(i=0;i<=a->top;i++)
		printf("%d ",a->val[i]);
	printf("\n");
}

int main()
{
	stack a;
	a.top = -1;
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int input;
		scanf("%d",&input);
		if(input == 1)
			insert(&a);
		else if(input == 2)
			pop(&a);
		else if(input == 3)
			disp(&a);
		else
			break;
	}
	return 0;
}