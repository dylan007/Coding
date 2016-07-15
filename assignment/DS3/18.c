/*
 * =====================================================================================
 *
 *       Filename:  18.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 16 April 2015 08:18:06  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shounak Dey (), dylandey1996@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

typedef struct list
{
	int data;
	struct list *next;
}list;

list *win[10000],*lose[10000];
int n;
int visited[10000];

void insert_win(int index,int x)
{
	list *new;
	new = (list *)malloc(sizeof(list));
	new->next = NULL;
	new->data = x;
	if(win[index]==NULL)
		win[index] = new;
	else
	{
		new->next = win[index];
		win[index] = new;
	}
}

void insert_lose(int index,int x)
{
	list *new;
	new = (list *)malloc(sizeof(list));
	new->next = NULL;
	new->data = x;
	if(lose[index]==NULL)
		lose[index] = new;
	else
	{
		new->next = lose[index];
		lose[index] = new;
	}
}

void dfs_win(int index)
{
	visited[index]=1;
	list *temp;
	temp = win[index];
	while(temp!=NULL)
	{
		if(visited[temp->data]!=1)
			dfs_win(temp->data);
		temp = temp->next;
	}
}

int check()
{
	int i;
	for(i=0;i<n;i++)
	{
		if(visited[i]==0)
			return 0;
	}
	return 1;
}

void dfs_lose(int index)
{
	visited[index]=1;
	list *temp;
	temp = lose[index];
	while(temp!=NULL)
	{
		if(visited[temp->data]!=1)
			dfs_lose(temp->data);
		temp = temp->next;
	}
}

int count()
{
	int i,c=0;
	for(i=0;i<n;i++)
		c+=visited[i];
	return c;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		memset(win,0,n*sizeof(list));
		memset(lose,0,n*sizeof(list));
		int i;
		for(i=0;i<n;i++)
		{
			int x,y;
			scanf("%d",&x);
			while(x--)
			{
				scanf("%d",&y);
				insert_win(y-1,i);
				insert_lose(i,y-1);
			}
		}
		/*for(i=0;i<n;i++)
		{
			list *temp;
			printf("%d\nwin\n",i);
			temp = win[i];
			while(temp!=NULL)
			{
				printf("%d ",temp->data);
				temp = temp->next;
			}
			printf("lose\n");
			temp = lose[i];
			while(temp!=NULL)
			{
				printf("%d ",temp->data);
				temp = temp->next;
			}

		}*/
		i=-1;
		memset(visited,0,4*n);
		while(check()!=1)
		{
			i++;
			memset(visited,0,4*n);
			dfs_win(i);	
		}
		memset(visited,0,4*n);
		dfs_lose(i);
		printf("%d\n",count());
	}
	return 0;
}
