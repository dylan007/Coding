/*
 * =====================================================================================
 *
 *       Filename:  p17.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 02 April 2015 07:42:19  IST
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

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}tree;

int n;

int find(int arr[],int start,int end,int x)
{
	while(start<=end)
	{
		if(arr[start]==x)
			return start;
		start++;
	}
	return start;
}

tree *buildtree(int pre[],int in[],int start,int end)
{
	static int p=0;
	if(start>end)
		return NULL;
	tree *new;
	new = (tree *)malloc(sizeof(tree));
	new->data = pre[p++]; 
	new->left = NULL;
	new->right = NULL;
	if(start==end)
		return new;
	else
	{
		int index;
		index = find(in,start,end,new->data);
		new->left = buildtree(pre,in,start,index-1);
		new->right = buildtree(pre,in,index+1,end);
		return new;
	}
}

/*void print(tree *head)
{
	if(head==NULL)
		return;
	print(head->left);
	printf("%d ",head->data);
	print(head->right);
}*/

tree *findnode(tree *head,int x)
{
	if(head==NULL)
		return NULL;
	if(head->data == x)
		return head;
	tree *ans = findnode(head->left,x);
	return ans?ans:findnode(head->right,x);
}

tree *lca(tree *head,tree *x,tree *y)
{
	if(!head)
		return NULL;
	if(head==x || head==y)
		return head;
	tree *l = lca(head->left,x,y);
	tree *r = lca(head->right,x,y);
	if(l&&r)
		return head;
	return (l==NULL)?r:l;
}

int main()
{
	scanf("%d",&n);
	int pre[n],in[n];
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&pre[i]);
	for(i=0;i<n;i++)
		scanf("%d",&in[i]);
	int q;
	tree *head;
	head = buildtree(pre,in,0,n-1);
	//print(head);
	scanf("%d",&q);
	while(q--)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		tree *ans;
		tree *X,*Y;
		X = findnode(head,x);
		Y = findnode(head,y); 
		ans = lca(head,X,Y);
		printf("%d\n",ans->data);
	}
	return 0;
}
