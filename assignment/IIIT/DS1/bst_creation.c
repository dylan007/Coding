#include<stdio.h>
#include<stdlib.h>

typedef struct tree 
{
	int val;
	int size;
	struct tree *left;
	struct tree *right;
	struct tree *parent;
}tree;

void insert(tree ** root, int x)
{
	tree *temp=NULL;
	if(!(*root))
	{
		temp = (tree *)malloc(sizeof(tree));
		temp->left = temp->right =NULL;
		temp ->val = x;
		temp->size = 1;
		temp->parent = NULL;
		*root = temp;
		return;
	}
	if(x<(*root)->val)
	{
		(*root)->size+=1;
		insert(&(*root)->left,x);
	}
	else if(x>(*root)->val)
	{
		(*root)->size+=1;
		insert(&(*root)->right, x);
	}
}

int rank(tree *root,int x)
{
	int rank = (root->left==NULL)?0:root->left->size + 1;
	tree *temp;
	temp = root;
	while(temp != root->parent)
	{
		if( temp == temp->parent->right)
			rank = rank + temp->parent->left->size + 1;
		temp = temp->parent;
	}
	return rank;
}

void print_tree(tree *root)
{
	if(root)
	{
		print_tree(root->left);
		printf("%d %d\n",root->val,root->size);
		print_tree(root->right);
	}
}


int main()
{
	int n,i,x;
	scanf("%d",&n);
	i=n-1;
	tree *root;
	root=(tree *)malloc(sizeof(tree));
	scanf("%d",&x);
	root->val=x;
	root->size = 1;
	root->left=NULL;
	root->right=NULL;
	root->parent = NULL;
	int count=0;
	while(i>0)
	{
		scanf("%d",&x);
		insert(&root,x);
		printf("%d\n",rank(root,x));
		count += rank(root,x);
		i--;
	}
	print_tree(root);
	printf("\n");
	printf("%d\n",count);
	return 0;
}
