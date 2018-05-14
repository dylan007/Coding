#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

typedef struct node{
	int data;
	struct node *left,*right;
}node;

node* new(int data)
{
	node *head = (node *)malloc(sizeof(node));
	head->data = data;
	head->left = head->right = NULL;
	return head;
}

node* insert(node *head,int data)
{
	node *temp = head;
	if(head == NULL)
		return new(data);
	while(1)
	{
		if(head->data > data)
		{
			if(head->left == NULL)
			{
				head->left = new(data);
				break;
			}
			else
				head = head->left;
		}
		else
		{
			if(head->right == NULL)
			{
				head->right = new(data);
				break;
			}
			else
				head = head->right;
		}
	}
	return temp;
}

void inorder(node *head)
{
	if(head==NULL)
		return;
	inorder(head->left);
	printf("%d ", head->data);
	inorder(head->right);
	return;
}

int main()
{	
	int n;
	scanf("%d",&n);
	int x;
	node *head = NULL;
	while(n--)
	{
		scanf("%d",&x);
		head = insert(head,x);
	}
	printf("Inorder : \n");
	inorder(head);
	return 0;
}