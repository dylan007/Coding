#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	int data;
	struct node *next;
}node;

node* push(node *head,int data)
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

int pop(node *head)
{
	node *temp = head;
	if(temp->next == NULL)
	{
		head= NULL;
		return temp->data;
	}
	node *prev;
	while(temp->next != NULL)
	{
		prev = temp;
		temp = temp->next;
	}
	prev->next = NULL;
	return temp->data;
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

int eval(int x,int y,char op)
{
	if(op=='+')
		return x+y;
	if(op=='-')
		return x-y;
	if(op=='/')
		return x/y;
	return x*y;
}

int main()
{
	node *head;
	head = NULL;
	char s[100];
	scanf("%s",s);
	int i;
	int curr=0;
	for(i=0;i<strlen(s);i++)
	{
		if(isdigit(s[i]))
			curr = curr*10 + (s[i]-'0');
		else if(s[i]==',')
		{
			head = push(head,curr);
			curr=0;
		}
		else
		{
			int x,y;
			x = pop(head);
			y = pop(head);
			//printf("%d %d\n",x,y);
			head = push(head , eval(y,x,s[i]));
		}
	}
	printf("%d\n", pop(head));
	return 0;
}