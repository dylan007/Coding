/*
 * =====================================================================================
 *
 *       Filename:  p20.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Monday 13 April 2015 07:06:23  IST
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
#include<string.h>
#include<math.h>
#include<limits.h>

typedef struct node
{
	int data;
	struct node *next;
}node;

node *adj[1000000];
int n;

int visited[1000000];

int maxdepth;
int last;
void dfs(int index,int depth)
{
	if(depth >= maxdepth)
	{
		last = index;
		maxdepth = depth;
	}
	visited[index]=1;
	node *temp;
	temp = adj[index];
	while(temp!=NULL)
	{
		if(visited[temp->data]==0)
			dfs(temp->data,depth+1);
		temp = temp->next;
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		int i,x,y;
		for(i=0;i<n;i++)
			adj[i]=NULL;
		for(i=0;i<(n-1);i++)
		{
			scanf("%d %d",&x,&y);
			node *new1;
			new1 = (node *)malloc(sizeof(node));
			new1->next = NULL;
			new1->data = y-1;
			new1->next = adj[x-1];
			adj[x-1] = new1;
			node *new2;
			new2 = (node *)malloc(sizeof(node));
			new2->next = NULL;
			new2->data = x-1;
			new2->next = adj[y-1];
			adj[y-1] = new2;
		}
		/*for(i=0;i<(n);i++)
		{
			node *temp = adj[i];
			while(temp!=NULL)
			{
				printf("%d ",temp->data);
				temp = temp->next;
			}
			printf("\n");
		}*/
		memset(visited,0,4*n);
		last=0;
		maxdepth = INT_MIN;
		dfs(0,0);
		int l=last;
		last = 0;
		maxdepth = INT_MIN;
		memset(visited,0,4*n);
		dfs(l,0);
		printf("%d\n",maxdepth+1);
	}
	return 0;
}
