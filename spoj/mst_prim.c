/*
 * =====================================================================================
 *
 *       Filename:  mst_prim.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Friday 17 April 2015 09:01:41  IST
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

typedef struct elem
{
	int vertex;
	int weight;
}elem;

typedef struct node
{
	int data;
	int W;
	struct node *next;
}node;

node *listify(node *head,int x,int w)
{
	printf("%d %d \n",x,w);
	node *new;
	new = (node *)malloc(sizeof(node));
	new->data = x;
	new->W = w;
	new->next = NULL;
	if(head==NULL)
		return new;
	else
	{
		new->next = head;
		return new;
	}
}

void swap(elem *a,elem *b)
{
	elem t;
	t = *a;
	*a = *b;
	*b = t;
}

/*void insert(elem *heap,int x,int w,int index)
{	
	elem *temp;
	heap[index]->vertex = x;
	heap[index]->weight = w;
	while((heap[index]->weight > heap[index/2]->weight) && index>0)
	{
		swap(&heap[index],&heap[index/2]);
		index = index/2;
	}
}*/

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int i,x,y,z;
	node *head[n];
	memset(head,0,4*sizeof(node));
	printf("%d %d\n",n,m);
	for(i=0;i<m;i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		x--;
		y--;
		printf("%d %d %d",x,y,z);
		head[x] = listify(head[x],y,z);
		head[y] = listify(head[y],x,z);
	}
	for(i=0;i<n;i++)
	{
		node *temp;
		temp = head[i];
		while(temp!=NULL)
		{
			printf("%d %d ",temp->data,temp->W);
			temp = temp->next;
		}
		printf("\n");
	}
	return 0;
}
