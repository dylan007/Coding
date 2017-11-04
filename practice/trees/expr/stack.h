#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	char op;
	int flag;
	struct node *left,*right;
}node;

typedef struct stack{
	node *data;
	struct stack *next;
}stack;

stack *create(node *data)
{
	stack *new = (stack *)malloc(sizeof(stack));
	new->data = data;
	new->next = NULL;
	return new;
}

stack *push(stack *head,node *data)
{
	if(head == NULL)
		return create(data);
	stack *temp = head;
	while(temp->next != NULL)
		temp = temp->next;
	temp->next = create(data);
	return head;
}

node *pop(stack **head)
{
	if(*head == NULL)
		return NULL;
	if((*head)->next == NULL)
	{
		node *temp  = (*head)->data;
		*head = (*head)->next;
		return temp;
	}
	stack *temp,*prev;
	temp = (*head)->next;
	prev = (*head);
	while(temp->next != NULL)
	{
		temp = temp->next;
		prev = prev->next;
	}
	prev->next = NULL;
	return temp->data;
}

void disp(stack *head)
{
	while(head)
	{
		if(head->data->flag)
			printf("%c",head->data->op);
		else
			printf("%d",head->data->data);
		head = head->next;
	}
	printf("\n");
}
