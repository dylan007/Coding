#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

node *create(char data)
{
	node *new = (node *)malloc(sizeof(node));
	new->data = data;
	new->left = new->right = NULL;
	return new;
}

int isOperand(char data)
{
	return data>='a' && data<='z';
}

node *construct(char *s,int l)
{
	stack *head = NULL;
	int i=0;
	for(i=0;i<l;i++)
	{
		if(isOperand(*(s+i)))
			head = push(head,create(*(s+i)));
		else
		{
			node *l,*r;
			r = pop(&head);
			l = pop(&head);
			node *p = create(*(s+i));
			p->left = l;
			p->right = r;
			head = push(head,p);
		}
	}		
	return pop(&head);
}

void inorder(node *head)
{
	if(head == NULL)
		return;
	inorder(head->left);
	printf("%c",head->data);
	inorder(head->right);
	return;
}
