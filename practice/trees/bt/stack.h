#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	char data;
	struct node *left,*right;
}node;

typedef struct stack{
	node *data;
	struct stack *next;
}stack;

stack *cs(node *data){
	stack *new = (stack *)malloc(sizeof(stack));
	new->data = data;
	new->next = NULL;
	return new;
}

stack *push(stack *head,node *data)
{
	if(head == NULL)
		return cs(data);
	stack *temp = head;
	while(temp->next)
		temp = temp->next;
	temp->next = cs(data);
	return head;
}

node *pop(stack **head)
{
	if(*head == NULL)
		return NULL;
	if((*head)->next == NULL)
		return (*head)->data;

	stack *temp = (*head)->next;
	stack *prev = (*head);
	while(temp->next  != NULL)
	{
		temp = temp->next;
		prev = prev->next;
	}
	prev->next = NULL;
	return temp->data;
}

void disp(stack *head)
{
	if(head == NULL)
	{
		printf("Empty list\n");
		return;
	}
	while(head)
	{
		printf("%d ",head->data->data);
		head = head->next;
	}
}
