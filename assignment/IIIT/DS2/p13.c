#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>

typedef struct node
{
	int data;
	struct node *left,*right;
}tree;

int min,maxdepth;

void insert(tree *head,int x,int depth)
{
	//printf("%d %d\n",x,depth);
	if(head->data > x)
	{
		if(head->left==NULL)
		{
			tree *new;
			new = (tree *)malloc(sizeof(tree));
			new->left = new->right = NULL;
			new->data = x;
			head->left = new;
			if(maxdepth == depth)
				min = min>x?x:min;
			else if(maxdepth < depth)
			{
				min = x;
				maxdepth=depth;
			}
		}
		else
			insert(head->left,x,depth+1);
	}
	if(head->data < x)
	{
		if(head->right==NULL)
		{
			tree *new;
			new = (tree *)malloc(sizeof(tree));
			new->left = new->right = NULL;
			new->data = x;
			head->right = new;
			if(maxdepth == depth)
				min = min>x?x:min;
			else if(maxdepth < depth)
			{
				min = x;
				maxdepth = depth;
			}
		}
		else
			insert(head->right , x , depth+1);
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		min = INT_MAX;
		maxdepth=0;
		int n;
		scanf("%d",&n);
		int a[n];
		int i;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		tree *head;
		head = (tree *)malloc(sizeof(tree));
		head->right = head->left = NULL;
		head->data = a[n-1];
		min = a[n-1];
		for(i=(n-2);i>=0;i--)
			insert(head,a[i],1);
		printf("%d %d\n",min,maxdepth);
		//delete(head);
	}
	return 0;
}
