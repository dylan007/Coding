#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next,*prev;
}node;

node* new(int data)
{
	node *head = (node *)malloc(sizeof(node));
	head->data = data;
	head->prev = head->next = NULL;
	return head;
}

node* enq(node *head,int data)
{
	node *temp = new(data);
	if(head == NULL)
	{
		temp->next = temp;
		temp->prev = temp;
		return temp;
	}
	node *last = head->prev;
	last->next = temp;
	temp->next = head;
	temp->prev = last;
	head->prev = temp;
	return head;
}

node* dq(node *head)
{
	if(head==NULL || head->next==head)
		return NULL;
	node *temp = head;
	head = head->next;
	head->prev = temp->prev;
	temp->prev->next = head;
	free(temp);
	return head;
}

void disp(node *head)
{
	node *ptr = head;
	if(head == NULL)
		return;
	while(head->next != ptr)
	{
		printf("%d ",head->data);
		head = head->next;
	}
	printf("%d\n",head->data);
	return;
}

int main()
{
	node *head = NULL;
	int c,x;
	while(1)
	{
		scanf("%d",&c);
		if(c==1)
		{
			scanf("%d",&x);
			head = enq(head,x);
		}
		else if(c==2)
		{
			if(head == NULL)
				printf("Empty\n");
			else
			{				
				printf("%d\n",head->data);
				head = dq(head);
			}
		}
		else if(c==3)
			disp(head);
		else
			break;
	}
}