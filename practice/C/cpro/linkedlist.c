#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

typedef struct
{
	int data;
	struct node *next;
}node;

node *list1,*list2;

void insert1(int x)
{
	if(list1==NULL)
	{
		list1 = (node *)malloc(sizeof(node));
		list1->data = x;
		list1->next=NULL;
	}
	else
	{
		node *t,*temp;
		temp = (node *)malloc(sizeof(node));
		t = list1;
		while(t->next!=NULL)
			t = t->next;
		t->next = temp;
		temp->next = NULL;
		temp->data = x;
	}
}

void insert2(int x)
{
	if(list2 == NULL)
	{
		list2 = (node *)malloc(sizeof(node));
		list2->data = x;
		list2->next = NULL;
	}
	else
	{
		node *temp,*t;
		temp = (node *)malloc(sizeof(node));
		t = list2;
		while(t->next!=NULL)
			t = t->next;
		t->next = temp;
		temp->next = NULL;
		temp->data = x;
	}
}

int check(int x)
{
	node *t;
	t = list1;
	while(t!=NULL)
	{
		if(t->data == x)
			return 1;
		t = t->next;
	}
	return 0;
}

int main()
{
	int n,x;
	list1 = list2 = NULL;
	printf("enter no of elements in list 1 and then the numbers: ");
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&x);
		insert1(x);
	}
	printf("enter the no of elements in list2 and then the numbers: ");
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&x);
		if(check(x)==1)
			insert2(x);
	}
	node *t;
	t = list2;
	while(t->next != NULL)
		printf("%d ",t->data),t = t->next;
	printf("%d\n",t->data);
	return 0;
}
