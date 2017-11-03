#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *left,*right;
}node;

typedef struct queue{	
	node *data;
	struct queue*next;
}queue;

queue *createqueue(node *data)
{
	queue *new = (queue *)malloc(sizeof(queue));
	new->data = data;
	new->next = NULL;
	return new;
}

queue *enq(queue *head,node *data)
{
	if(head == NULL)
		return createqueue(data);
	queue *temp;
	temp = head;
	while(temp->next != NULL)
		temp = temp->next;
	temp->next = createqueue(data);
	return head;
}

node *deq(queue **head)
{
	if(*head==NULL)
		return NULL;
	queue *temp = (*head);
	*head = (*head)->next;
	return temp->data;
}

int isEmpty(queue *head)
{
	return head==NULL;
}


void disp(queue *head)
{
	while(head != NULL)
	{
		printf("%d ",head->data->data);
		head = head->next;
	}
	printf("\n");
}
