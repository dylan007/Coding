#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

node* enqueue(node *head,int data)
{
	node *new = (node *)malloc(sizeof(node));
	new->data = data;
	new->next = NULL;
	if(head == NULL)
		return new;
	node *temp = head;
	while(temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	return head;
}

node* dequeue(node *head)
{
	if(head == NULL)
		return NULL;
	if(head->next == NULL)
	{
		free(head);
		return NULL;
	}
	node *temp = head->next;
	free(head);
	return temp;
}

void display(node *head)
{
	node *temp = head;
	while(temp != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
	return;
}

int main()
{
	node *head;
	head = NULL;
	int c,x;
	scanf("%d",&c);
	while(c<=3)
	{
		if(c==1)
		{
			scanf("%d",&x);
			head = enqueue(head,x);
		} 
		else if(c==2)
			head = dequeue(head);
		else
			display(head);
		scanf("%d",&c);
	}
	return 0;
}