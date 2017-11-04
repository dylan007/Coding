#include <stdio.h>
#include <stdlib.h>
#include "bstqueue.h"


node *create(int data)
{
	node *new = (node *)malloc(sizeof(node));
	new->data = data;
	new->left = new->right = NULL;
	return new;
}

node *insert(node *head,int data){
	if(head == NULL)
		return create(data);
	if(head->data < data)
		head->right = insert(head->right,data);
	else
		head->left = insert(head->left,data);
	return head;
}

void inorder(node *head)
{
	if(head == NULL)
		return;
	inorder(head->left);
	printf("%d ",head->data);
	inorder(head->right);
}

void preorder(node *head)
{
	if(head==NULL)
		return;
	printf("%d ",head->data);
	preorder(head->left);
	preorder(head->right);
}

void postorder(node *head)
{
	if(head==NULL)
		return;
	postorder(head->left);
	postorder(head->right);
	printf("%d ",head->data);
}

node* search(node *head,int data)
{
	if(head == NULL)
		return NULL;
	if(head->data == data)
		return head;
	if(head->data > data)
		return search(head->left,data);
	return search(head->right,data);
}

node *find_parent(node *head,node *child)
{
	if(head == child)
		return head;
	if(head->left==child || head->right==child)
		return head;
	if(head->data > child->data)
		return find_parent(head->left,child);
	return find_parent(head->right,child);
}

node *find_max(node *head)
{
	if(head->right == NULL)
		return head;
	return find_max(head->right);
}

node *find_min(node *head){
	if(head->left == NULL)
		return head;
	return find_min(head->left);
}

node *delete(node *head,int data)
{
	if(head == NULL)
		return NULL;
	node *child = search(head,data);
	if(child == NULL)
		return head;
	node *parent = find_parent(head,search(head,data));
	//printf("parent: %d , child = %d\n",parent->data,child->data);
	if(child->left==child->right && child->left==NULL)
	{
		//printf("Case 1\n");
		if(child == parent)
			return NULL;
		if(parent->data < data)
			parent->right =NULL;
		else
			parent->left = NULL;
		return head;
	}
	else if(child->left==NULL || child->right==NULL)
	{
		//printf("Case 2\n");
		if(child->left){
			if(parent->data < data)
				parent->right = child->left;
			else
				parent->left = child->left;
		}
		else{
			if(parent->data < data)
				parent->right = child->right;
			else
				parent->left = child->right;
		}
		return head;
	}
	else
	{
		//printf("Case 3\n");
		//printf("%d",child->data);
		node *min = find_max(child->left);
		child->left = delete(child->left,min->data);
		child->data = min->data;
		return head;
	}
}

void levelorder(node *head)
{
	queue *q= NULL;
	q = enq(q,head);
	printf("Level order traversal of the given tree...\n");
	while(!isEmpty(q))
	{
		node *temp,*l,*r;
		temp = deq(&q);
		l = temp->left;
		r = temp->right;
		if(l)
			q = enq(q,l);
		if(r)
			q = enq(q,r);
		printf("%d ",temp->data);
		//disp(q);
	}
	printf("\n");
}

