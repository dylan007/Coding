/*
 * =====================================================================================
 *
 *       Filename:  p24.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Friday 10 April 2015 06:42:06  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shounak Dey (), dylandey1996@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>

#define max(a,b) a>b?a:b

typedef struct node
{
	int data;
	struct node *left,*right;
	int height;
	int rank;
}tree;

int hgt(tree *x)
{
	if(x==NULL)
		return 0;
	return x->height;
}

tree *right_rotate(tree *head)
{
	tree *x = head->left;
	tree *T2 = x->right;
	x->right = head;
	head->left = T2;
	head->height = max(hgt(head->left), hgt(head->right))+1;
	x->height = max(hgt(x->left), hgt(x->right))+1;
	return x;
}

tree *left_rotate(tree *head)
{
	tree *x = head->right;
	tree *T2 = x->left;
	x->left = head;
	head->right = T2;
	head->height = max(hgt(head->left), hgt(head->right))+1;
	x->height = max(hgt(x->left), hgt(x->right))+1;
	return x;
}

int bal(tree *head)
{
	if(head==NULL)
		return 0;
	else
		return hgt(head->left) - hgt(head->right);
}

tree *insert(tree *head,int x,int R)
{
	if(head==NULL)
	{
		tree *new;
		new = (tree *)malloc(sizeof(tree));
		new->data = x;
		new->height = 1;
		new->rank = R;
		new->left = new->right = NULL;
		return new;
	}
	if(x < head->data)
	{
		head->left = insert(head->left,x,head->rank);
		head->rank++;
	}
	else if(x > head->data)
		head->right = insert(head->right,x,head->rank+1);
	head->height = max(hgt(head->left),hgt(head->right))+1;
	int balance = bal(head);
	if(balance > 1 &&  x < head->left->data)
		return right_rotate(head);
	else if(balance < -1 && x > head->right->data)
		return left_rotate(head);
	else if(balance > 1 && x > head->left->data)
	{
		head->left = left_rotate(head->left);
		return right_rotate(head);
	}
	else if(balance < -1 && x < head->right->data)
	{
		head->right = right_rotate(head->right);
		return left_rotate(head);
	}
	return head;
}

int search(tree *head,int x)
{
	if(head==NULL)
		return 0;
	if(head->data == x)
		return 1;
	if(x<head->data)
		return search(head->left ,x);
	else
		return search(head->right,x);
}

void inorder(tree *head)
{
	if(head== NULL)
		return;
	printf("%d\n%d\n",head->data,head->rank);
	inorder(head->left);
	inorder(head->right);
}

int size_left(tree *head)
{
	if(head == NULL)
		return 0;
	return 1+size_left(head->left)+size_left(head->right);
}

int find_k(tree *head,int k)
{
	if(head==NULL)
		return 0;
	int l = size_left(head->left);
	if(l==(k-1))
		return head->data;
	else if(l>=(k))
		return find_k(head->left,k);
	else
		return find_k(head->right,k-l-1);
}

int main()
{
	char str[20];
	int x;
	tree *head;
	while(1)
	{
		scanf("%s%*C",str);
		int change=0;
		change = str[0]-'A';
		if(change==16)
			break;
		scanf("%d",&x);
		int ans;
		tree *temp;
		switch(change)
		{
			case 18:
				head = insert(head,x,0);
				break;
			case 2:
				if(search(head,x)==1)
					printf("YES\n");
				else
					printf("NO\n");
				break;
			case 7:
				inorder(head);
				ans = find_k(head,x);
				if(ans == 0)
					printf("NONE\n");
				else
					printf("%d\n",ans);
				break;	
			case 17:
				//temp = lookup(head,x);
				//if(temp!=NULL)
				//	printf("%d\n",temp->data);
				//printf("%d\n",size_left(temp));
				break;
		}
	}
	return 0;
}
