#include <stdio.h>
#include <stdlib.h>

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
			new=(tree *)malloc(sizeof(tree));
			new->left=new->right=NULL;
			new->data=x;
			head->left=new;
		}
		else
			insert(head->left,x);
	}
}

void printtree(tree *head)
{
	if(head == NULL)
		return;
	printtree(head->left);
	printf("%d ",head->data);
	printtree(head->right);
}

void postorder(tree *head)
{
	if(head==NULL)
		return;
	postorder(head->left);
	postorder(head->right);
	printf("%d ",head->data);
}

void preorder(tree* head)
{
	if(head == NULL)
		return;
	printf("%d ",head->data);
	preorder(head->left);
	preorder(head->right);
}

int size(tree *head)
{
	if(head==NULL)
		return 0;
	else
		return (size(head->left) + 1 + size(head->right));
}

int maxDepth(tree *head)
{
	if(head==NULL)
		return 0;
	else
	{
		int ldepth,rdepth;
		ldepth = maxDepth(head->left);
	 	rdepth = maxDepth(head->right);

		if(ldepth > rdepth)
			return (ldepth+1);
		else
			return (rdepth+1);
	}
}

void printArray(int ints[], int len)
{
	int i;
	for(i=0;i<len;i++)
		printf("%d ",ints[i]);
	printf("\n");
}


void printPathsRecur(tree *head,int path[],int pathLen)
{
	if(head==NULL)
		return;
	 
	path[pathLen] = head->data;
	pathLen++;

	if(head->left==NULL && head->right==NULL)
		printArray(path,pathLen);
	else
	{
		printPathsRecur(head->left,path,pathLen);
		printPathsRecur(head->right,path,pathLen);
	}
}

void printPaths(tree *head)
{
	int path[1000];
	printPathsRecur(head,path,0);
}

int look(tree *head,int x)
{
	if(head==NULL)
		return -1;
	else if(x > head->data)
		return look(head->right,x);
	else if(x < head->data)
		return look(head->left,x);
	else
		return 1;
}

int min(tree *head)
{
	while(head->left!=NULL)
		head = head->left;
	return head->data;
}

void delete(tree *head,int x)
{
	tree *node;
	node = NULL;
	if(look(head,x) == -1)
		return ;
	else
	{
		int f=0;
		while(head->data != x)
		{
			if(head->data > x)
			{
				f=1;
				node = head;
				head = head->left;
			}
			else if(head->data < x)
			{
				f=2;
				node = head;
				head = head->right;
			}
			else
				break;
		}
		int MIN;
		MIN = min(head->right);
		if((head->left == NULL) && (head->right != NULL))
		{
			if(f==1)
			{
				node->left = head->right;
				free(head);
			}
			else if(f==2)
			{
				node->right = head->right;
				free(head);
			}
		}	
		else if((head->left != NULL) && (head->right == NULL))
		{
			if(f==1)
			{
				node->left = head->left;
				free(head);
			}
			if(f==2)
			{
				node->right = head->left;
				free(head);
			}
		}
		else if((head->left == NULL) && (head->right == NULL))
			free(head);
		else
		{
			head->data = MIN;
			head = head->right;
			while(head->left != NULL)
				head = head->left;
			free(head);
		}
	}
}


int main()
{
	int n,i,x,y;
	scanf("%d",&n);
	scanf("%d",&x);
	tree *head;
	head=(tree *)malloc(sizeof(tree));
	head->right=head->right=NULL;
	n--;
	head->data=x;
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		insert(head,x);
	}
	int choice;
	printf("\n1.preorder\n2.inorder\n3.postorder\n4.print the paths possible\n5.delete\n6.look for a number\n7.exit\nEnter your choice:");
	scanf("%d",&choice);
	while(choice!=7)
	{
		switch(choice)
		{
			case 1:
				preorder(head);
				break;
			case 2:
				printtree(head);
				break;
			case 3:
				postorder(head);
				break;
			case 4:
				printPaths(head);
				break;
			case 6:
				printf("Enter the number to be looked for: ");
				scanf("%d",&x);
				if(look(head,x)==1)
					printf("%d exists in the tree\n",x);
				else
					printf("No, %d does not exist in the tree\n",x);
				break;
			case 5:
				printf("Enter the number to be deleted\n");
				scanf("%d",&x);
				delete(head,x);
				break;
		}
		printf("\n1.preorder\n2.inorder\n3.postorder\n4.print the paths possible\n5.delete\n6.look for a number\n7.exit\nEnter your choice:");
		scanf("%d",&choice);
	}
	return 0;
}
