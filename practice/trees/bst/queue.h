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
	queue *prev,*temp;
	if((*head)->next == NULL)
	{
		node *temp = (*head)->data;
		*head = NULL;
		return temp;
	}
	prev = *head;
	temp = prev->next;
	while(temp->next != NULL)
	{
		prev = temp;
		temp = temp->next;
	}
	prev->next = NULL;
	return temp->data;
}

int isEmpty(queue *head)
{
	return head==NULL;
}
