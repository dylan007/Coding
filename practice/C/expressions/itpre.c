#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	char data;
	struct node *next;
}node;

node *create(char data)
{
	node *new = (node *)malloc(sizeof(node));
	new->data = data;
	new->next = NULL;
	return new;
}

node *push(node *head,char data)
{
	if(head == NULL)
		return create(data);
	node *temp = head;
	while(temp->next != NULL)
		temp = temp->next;
	temp->next = create(data);
	return head;
}

char pop(node **head)
{
	node *temp = *head;
	if(temp->next == NULL)
	{
		*head = NULL;
		return temp->data;
	}
	node *prev = *head;
	temp = temp->next;
	while(temp->next != NULL)
	{
		temp = temp->next;
		prev = prev->next;
	}
	prev->next = NULL;
	return temp->data;
}

int isEmpty(node *head)
{
	return head==NULL;
}

void disp(node *head)
{
	while(head)
	{
		printf("%c",head->data);
		head = head->next;
	}
	printf("\n");
	return;
}

int prec(char x)
{
	if(x=='+' || x=='-')
		return 1;
	if(x=='*' || x=='/')
		return 2;
	if(x=='$')
		return 3;
	if(x==')' || x=='(')
		return 4;
	return -1;
}

int isop(char x)
{
	return (x>='0' && x<='9');
}

char top(node *head)
{
	while(head->next != NULL)
		head = head->next;
	return head->data;
}

int main()
{
	char s[100];
	scanf("%s",s);
	int i;
	node *head = NULL;
	for(i=0;i<strlen(s);i--)
	{
		if(isop(s[i]))
			printf("%c",s[i]);
		else
		{
		//	printf("%c not op\n",s[i]);
			if(s[i] == '(')
				head = push(head,s[i]);
			else if(s[i] == ')')
			{
				while(top(head) != '(')
					printf("%c",pop(&head));
				pop(&head);
			}
			else
			{
				while(head!=NULL && prec(s[i])<=prec(top(head)))
					printf("%c",pop(&head));
				head = push(head,s[i]);
			}
		}
		//printf("\nstack: ");
		//disp(head);
	}
	disp(head);
	while(head)
		printf("%c",pop(&head));
	printf("\n");
	return 0;
}
