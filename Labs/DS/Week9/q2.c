#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	int data;
	struct node *next,*prev;
}node;

node* push(node *head,int data)
{
	node *new = (node *)malloc(sizeof(node));
	new->data = data;
	if(head == NULL)
	{
		new->next = new;
		new->prev = new;
		return new;
	}
	node *temp = head->prev;
	temp->next = new;
	new->next = head;
	new->prev = temp;
	head->prev = new;
	return head;
}

void disp(node *head)
{
	node *temp = head->prev;
	while(temp != head)
	{
		printf("%d",temp->data);
		temp = temp->prev;
	}
	printf("%d\n",temp->data);
	return;
}

node *add(node *h1,node *h2,int z)
{
	while(z--)
		h2 = push(h2,0);
	int c=0;
	node *p1,*p2;
	p1 = h1;
	p2 = h2;
	node *ans;
	ans = NULL;
	node *last = h1->prev;
	while(p1 != last)
	{
		ans = push(ans,(p1->data + p2->data + c)%10);
		c = (c + p1->data + p2->data)/10;
		p1 = p1->next;
		p2 = p2->next;
	}
	ans = push(ans,(p1->data + p2->data + c)%10);
	c = (c + p1->data + p2->data)/10;
	if(c>0)
		ans = push(ans,c);
	return ans;
}

int main()
{
	node *h1,*h2;
	h1 = h2 = NULL;
	char s1[1000],s2[1000];
	scanf("%s",s1);
	int i;
	for(i=strlen(s1)-1;i>=0;i--)
		h1 = push(h1,s1[i]-48);
	//disp(h1);	
	scanf("%*c%s",s2);
	for(i=strlen(s2)-1;i>=0;i--)
		h2 = push(h2,s2[i]-48);
	//disp(h2);
	node *ans;
	if(strlen(s1)>strlen(s2))
		ans = add(h1,h2,strlen(s1)-strlen(s2));
	else
		ans = add(h2,h1,strlen(s2)-strlen(s1));
	disp(ans);
	return 0;
}