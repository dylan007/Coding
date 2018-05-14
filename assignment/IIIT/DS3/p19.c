/*
 * =====================================================================================
 *
 *       Filename:  p19.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Friday 03 April 2015 04:15:46  IST
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

#define INDEX(c) ((int)c - (int)'0')

typedef struct node
{
	char data;
	int count;
	int null;
	struct node *child[11];
}trie;

int same=0;

trie *create(void)
{
	trie *node;
	node = (trie *)malloc(sizeof(trie));
	int i;
	node->data = '\0';
	node->count=0;
	node->null=0;
	for(i=0;i<11;i++)
		node->child[i] = NULL;
	return node;
}

void insert(trie *head,char str[])
{
	int len;
	len = strlen(str);
	int i;
	int index;
	same=1;
	for(i=0;i<len;i++)
	{
		index = INDEX(str[i]);
		if(head->child[index]==NULL)
		{
			trie *new;
			new = create();
			new->data = str[i];
			head->child[index] = new;
			same=0;
		}
		head->count++;
		head = head->child[index];
	}
	trie *new;
	new = create();
	new->null=1;
	new->data = '\0';
	head->child[10] = new;
}

/*void print(trie *head)
{
	if(head==NULL)
		return;
	int i;
	printf("%c",head->data);
	int flag=1;
	for(i=0;i<10;i++)
		print(head->child[i]);
	printf("\n");
}*/

int check(trie *head)
{
	if(head==NULL)
		return 0;
	int i;
	int c=0;
	for(i=0;i<10;i++)
		c += (head->child[i]!=NULL);
	if(head->child[10]!=NULL && c!=0)
		return 1;
	c=0;
	for(i=0;i<10;i++)
		c = c|check(head->child[i]);
	return c;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		int i;
		trie *head;
		head = create();
		char inp[20];
		for(i=0;i<n;i++)
		{
			scanf("%s",inp);
			insert(head,inp);
			if(same==1)
				break;
		}
		if(same==1)
			printf("NO\n");
		else
		{
			//print(head);
			int flag=0;
			for(i=0;i<10;i++)
				flag = flag | check(head->child[i]);
			if(flag==1)
				printf("NO\n");
			else
				printf("YES\n");
		}
	}
	return 0;
}
