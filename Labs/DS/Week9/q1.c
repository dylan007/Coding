#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

node *push(node *head,int data)
{
	node *temp = (node *)malloc(sizeof(node));
	temp->data = data;
	if(head == NULL)
	{
		temp->next = temp;
		return temp;
	}
	node *ptr = head;
	while(ptr->next != head)
		ptr = ptr->next;
	ptr->next = temp;
	temp->next = head;
	return head;
}

void disp(node *head)
{
	node *temp = head;
	while(temp->next != head)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("%d\n",temp->data);
	return;
}

int isIn(node *head,int data)
{
	node *temp = head;
	if(head == NULL)
		return 0;
	while(temp->next != head)
	{
		if(temp->data == data)
			return 1;
		temp = temp->next;
	} 
	if(temp->data == data)
		return 1;
	return 0;
}

node *un(node *h1,node *h2)
{
	node *ans;
	ans = NULL;
	node *p1 = h1;
	if(p1 == NULL)
		return h2;
	if(h2 == NULL)
		return h1;
	while(p1->next != h1)
	{
		if(!isIn(h2,p1->data))
			ans = push(ans,p1->data);
		p1 = p1->next;
	}
	if(!isIn(h2,p1->data))
		ans = push(ans,p1->data);
	node *p2 = h2;
	while(p2->next != h2)
	{
		ans = push(ans,p2->data);
		p2 = p2->next;
	}
	ans = push(ans,p2->data);
	return ans;
}

node *in(node *h1,node *h2)
{
	node *ans;
	ans = NULL;
	node *p1 = h1;
	node *p2 = h2;
	if(p1==NULL || p2==NULL)
		return NULL;
	while(p1->next != h1)
	{
		if(isIn(h2,p1->data))
			ans = push(ans,p1->data);
		p1 = p1->next;
	}
	if(isIn(h2,p1->data))
		ans = push(ans,p1->data);
	return ans;
}

int main()
{
	int x,n;
	node *h1;
	node *h2;
	scanf("%d",&n);
	h1 = NULL;
	while(n--)
	{
		scanf("%d",&x);
		h1 = push(h1,x);
	}
	scanf("%d",&n);
	h2 = NULL;
	while(n--)
	{
		scanf("%d",&x);
		h2 = push(h2,x);
	}
	disp(h1);
	disp(h2);
	node *u,*i;
	u = un(h1,h2);
	i = in(h1,h2);
	printf("Union\n");
	disp(u);
	printf("Intersection\n");
	disp(i);
	return 0;
}