#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int coeff,exp;
	struct node *next;
}node;

node* new(int coeff,int exp)
{
	node *head = (node *)malloc(sizeof(node));
	head->coeff = coeff;
	head->exp = exp;
	head->next = NULL;
	return head;
}

node *insert(node *head,int coeff,int exp)
{
	node *x = new(coeff,exp);
	if(head == NULL)
		return x;
	node *temp = head;
	while(head->next != NULL)
		head = head->next;
	head->next = x;
	return temp;
}

node* update(node *head,int coeff,int exp)
{
	node *temp = head;
	if(head == NULL)
		return new(coeff,exp);
	while(head->next != NULL)
	{
		if(exp == head->exp)
		{
			head->coeff += coeff;
			return temp;
		}
		head = head->next;
	}
	if(exp == head->exp)
	{
		head->coeff += coeff;
		return temp;
	}
	head->next = new(coeff,exp);
	return temp;
}

node* subtract(node *h1,node *h2)
{
	node *sub = NULL;
	node *ptr = h1;
	while(ptr!= NULL)
	{
		sub = insert(sub,ptr->coeff,ptr->exp);
		ptr = ptr->next;
	}
	ptr = h2;
	while(ptr!=NULL)
	{
		sub = update(sub,0-ptr->coeff,ptr->exp);
		ptr = ptr->next;
	}
	return sub;
}

node *mul(node *h1,node *h2)
{
	node *p1 = h1;
	node *p2;
	node *m = NULL;
	while(p1 != NULL)
	{
		p2 = h2;
		while(p2 != NULL)
		{
			m = update(m,(p1->coeff)*(p2->coeff),(p1->exp)+(p2->exp));
			p2 = p2->next;
		}
		p1 = p1->next;
	}
	return m;
}

void disp(node *head)
{
	while(head != NULL)
	{
		printf("%d %d\n",head->coeff,head->exp);
		head = head->next;
	}
	printf("\n");
	return;
}

int main()
{
	printf("Enter first polynomial in coeff,exp form: \n");
	int n;
	scanf("%d",&n);
	int c,e;
	node *h1,*h2;
	h1 = NULL;
	h2 = NULL;
	while(n--)
	{
		scanf("%d %d",&c,&e);	
		h1 = insert(h1,c,e);
	}
	printf("Enter second polynomial in coeff,exp form: \n");
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d %d",&c,&e);	
		h2 = insert(h2,c,e);
	}
	printf("Polynomial A - Polynomial B : \n");
	disp(subtract(h1,h2));
	printf("Polynomial A * Polynomial B : \n");
	disp(mul(h1,h2));
	return 0;
}