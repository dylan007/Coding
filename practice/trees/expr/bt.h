#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

node *cnode(int data,char op,int flag)
{
	node *new = (node *)malloc(sizeof(node));
	new->data = data;
	new->op = op;
	new->flag = flag;
	new->left = new->right = NULL;
	return new;
}

int isOperand(char x){
	if(x>='1' && x<='9')
		return 1;
	return 0;
}

node *construct(char *s,int l)
{
	int i;
	stack *head = NULL;
	for(i=0;i<l;i++)
	{
		disp(head);
		if(isOperand(*(s+i)))
			head = push(head,cnode(*(s+i) - '0','a',0));
		else
		{
			node *l,*r,*p;
			p = cnode(0,*(s+i),1);
			r = pop(&head);
			l = pop(&head);
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
	if(head->flag)
		printf("%c",head->op);
	else
		printf("%d",head->data);
	inorder(head->right);
}

int calc(int a, int b, char op)
{
	if(op=='+')
		return a+b;
	if(op=='-')
		return a-b;
	if(op=='/')
		return a/b;
	if(op=='*')
		return a*b;
}

int evaltree(node *head)
{
	if(head->flag == 0)
		return head->data;
	else
		return calc(evaltree(head->left),evaltree(head->right),head->op);
}
