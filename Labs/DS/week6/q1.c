#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef struct node{
	char vals[MAX][MAX];
	int front,rear;
}cq;

void push(cq *a)
{
	if(a->front<0 && a->rear<0)
	{
		a->front = 0;
		a->rear = 0;
	}
	else
	{
		if(a->rear == (MAX-1))
			a->rear = 0;
		else
			a->rear++;
	}
	scanf("%s",a->vals[a->rear]);
	return;
}

void pop(cq *a)
{
	if(a->front<0 && a->rear<0)
		printf("The Queue is empty\n");
	else
	{
		printf("%s\n",a->vals[a->front]);
		if(a->front == a->rear)
		{
			a->front = -1;
			a->rear = -1;
		}
		else
			a->front = (a->front + 1)%MAX;
	}
	return;
}

void display(cq *a)
{
	int i,l=a->front;
	int r = a->rear;
	if(l <= r)
	{
		for(i=l;i<=r;i++)
			printf("%s -> ",a->vals[i]);
	}
	else
	{
		for(i=l;i<MAX;i++)
			printf("%s -> ",a->vals[i]);
		for(i=0;i<=r;i++)
			printf("%s -> ",a->vals[i]);
	}
	printf("\n");
	return;
}

int main()
{
	int input;
	cq a;
	a.rear = -1;
	a.front = -1;
	while(1)
	{
		scanf("%d",&input);
		if(input>3)
			break;
		if(input==1)
			push(&a);
		else if(input==2)
			pop(&a);
		else
			display(&a);
	}
	return 0;
}
