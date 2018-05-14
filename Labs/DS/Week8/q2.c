#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	char data;
	struct node *next;
}node;

void disp(node *head)
{
	node *temp = head;
	while(temp->next != head)
	{
		printf("%c",temp->data);
		temp = temp->next;
	}
	printf("%c\n",temp->data);
	return;
}

node* push(node *head,char data)
{
	node *new = (node *)malloc(sizeof(node));
	new->data = data;
	if(head == NULL)
	{
		new->next = new;
		return new;
	}
	node *temp = head;
	while(temp->next != head)
		temp = temp->next;
	temp->next = new;
	new->next = head;
	return head;
}

node *sot(node *h1,node *h2)
{
	node *p1,*p2,*head;
	p1 = h1;
	p2 = h2;
	head = NULL;
	int l1=0,l2=0;
	while(p1->next!=h1)
	{
		p1 = p1->next;
		l1++;
	}
	l1++;
	while(p2->next!=h2)
	{
		p2 = p2->next;
		l2++;
	}
	l2++;
	p1 = h1;
	p2 = h2;
	while(l1>0 && l2>0)
	{
		if(p1->data >= p2->data)
		{
			head = push(head,p2->data);
			p2 = p2->next;
			l2--;
		}
		else
		{
			head = push(head,p1->data);
			p1 = p1->next;
			l1--;
		}
	}
	while(l1>0)
	{
		head = push(head,p1->data);
		p1 = p1->next;
		l1--;
	}
	while(l2>0)
	{
		head = push(head,p2->data);
		p2 = p2->next;
		l2--;
	}
	return head;
}

int main()
{
	node *h1,*h2;
	h1 = NULL;
	h2 = NULL;
	int n;
	scanf("%d",&n);
	getchar();
	char x;
	while(n--)
	{
		scanf("%c",&x);
		h1 = push(h1,x);
	}
	scanf("%d",&n);
	getchar();
	while(n--)
	{
		scanf("%c",&x);
		h2 = push(h2,x);
	}
	node *head = sot(h1,h2);
	disp(head);
	return 0;
}