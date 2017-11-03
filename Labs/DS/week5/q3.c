#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct node{
	int arr[MAX];
	int top1,top2;
}stack;

void push(stack *s,int data,int c)
{
	if(s->top1 == (s->top2-1))
	{
		printf("Stack if full\n");
		return;
	}
	if(c==1)
	{
		s->top1 ++;
		s->arr[s->top1] = data;
		return;
	}
	if(c==2)
	{
		s->top2 --;
		s->arr[s->top2] = data;
		return;
	}
	return;
}

int pop(stack *s,int c)
{
	if(c == 1)
	{
		if(s->top1 == -1)
			return -1;
		return s->arr[s->top1--];
	}
	if(c==2)
	{
		if(s->top2 == MAX)
			return -1;
		return s->arr[s->top2++];
	}
	return;
}

void display(stack s,int c)
{
	int i;
	if(c==1)
	{
		for(i=0;i<=s.top1;i++)
			printf("%d ",s.arr[i]);
		printf("\n");
	}
	else
	{
		for(i=MAX-1;i>=s.top2;i--)
			printf("%d ",s.arr[i]);
		printf("\n");
	}
}

int main()
{
	int q,x,c;
	scanf("%d",&q);
	stack s;
	s.top1 = -1;
	s.top2 = MAX;
	while(q!=4)
	{
		if(q==1)
		{
			scanf("%d %d",&x,&c);
			push(&s,x,c);
		}
		if(q==2)
		{
			scanf("%d",&c);
			int x = pop(&s,c);
			if(x>=0)
				printf("%d\n",x);
			else
				printf("-1\n");
		}
		if(q == 3)
		{
			scanf("%d",&c);
			display(s,c);
		}
		scanf("%d",&q);
	}
	return 0;
}