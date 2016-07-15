#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}queue;

queue *top;

void enq(int x)
{
	if(top == NULL)
	{
		top = (queue *)malloc(sizeof(queue));
		top->next = NULL;
		top->data = x;
		return;
	}
	queue *new;
	new = (queue *)malloc(sizeof(queue));
	new->next = top;
	new->data = x;
	top = new;
}

void deq()
{
	if(top == NULL)
		printf("queue is empty\n");
	else
	{
		queue *temp,*prev;
		temp = top;
		while(temp->next != NULL)
		{
			prev = temp;
			temp = temp->next;	
		}
		prev->next=NULL;
	}
}

void print()
{
	queue *temp;
	temp = top;
	while(temp->next != NULL)
	{
		printf("%d->",temp->data);
		temp = temp->next;
	}
	printf("%d\n",temp->data);
}

int main()
{
	int x,temp;
	printf("1.enqueue\n2.dequeue\n3.print\n4.exit\n");
	scanf("%d",&x);
	while(x>0 && x<4)
	{
		switch(x)
		{
			case 1:
				printf("Enter the number: ");
				scanf("%d",&temp);
				enq(temp);
				break;
			case 2:
				deq();
				break;
			case 3:
				print();
				break;
		}
		printf("1.enqueue\n2.dequeue\n3.print\n4.exit\n");
		scanf("%d",&x);
	}
	return 0;
}
