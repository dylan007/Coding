#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}tree;

int insert(tree *head,int x)
{
	if(x>head->data)
	{
		if(head->right==NULL)
		{
			tree *new;
			new=(tree *)malloc(sizeof(tree));
			new->left=new->right=NULL;
			new->data=x;
			head->right=new;
		}
		else
			insert(head->right,x);
	}
	else if(x<head->data)
	{
		if(head->left==NULL)
		{	
			tree *new;
			new = (tree *)malloc(sizeof(tree));
			new->left=new->right=NULL;
			new->data=x;
			head->left=new;
		}
		else
			insert(head->left,x);
	}
}

void postorder(tree *head)
{
	if(head==NULL)
		return;
	postorder(head->left);
	postorder(head->right);
	printf("%d\n",head->data);
}


int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		tree *head;
		int x;
		scanf("%d",&x);
		head = (tree *)malloc(sizeof(tree));
		head->left = head->right = NULL;
		head->data=x;
		n--;
		while(n--)
		{
			scanf("%d",&x);
			insert(head,x);
		}
		postorder(head);
		printf("\n");
		free(head);
	}
	return 0;
}
