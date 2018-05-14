#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	char word[100];
	struct node *next,*prev;
}node;

node* push(node *head,char s[])
{
	node *new = (node *)malloc(sizeof(node));
	strcpy(new->word,s);
	new->next = NULL;
	if(head == NULL)
	{
		new->prev = NULL;
		return new;
	}
	node *temp;
	temp = head;
	while(temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	new->prev = temp;
	return head;
}

void disp(node *head)
{
	node *temp = head;
	while(temp != NULL)
	{
		printf("%s ",temp->word);
		temp = temp->next;
	}
	printf("\n");
}

node *rev(node *head)
{
	node *temp = head;
	while(temp->next != NULL)
		temp = temp->next;
	node *last = temp;
	node *ptr;
	while(temp != NULL)
	{
		ptr = temp->prev;
		temp->prev = temp->next;
		temp->next = ptr;
		temp = ptr;
	}
	return last;
}

int main()
{
	char s[100];
	int n;
	scanf("%d%*c",&n);
	node *ans;
	ans = NULL;
	while(n--)
	{
		scanf("%s",s);
		ans = push(ans,s);
	}
	disp(ans);
	ans = rev(ans);
	disp(ans);
	return 0;
}