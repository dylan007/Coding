#include <stdio.h>
#include <stdlib.h>
 
#define max(a,b) (a>b?a:b)

typedef struct node{
	int coeff;
	int row;
	struct node *next;
}node;

node *create(int coeff,int row)
{
	node *new = (node *)malloc(sizeof(node));
	new->coeff = coeff;
	new->row = row;
	return new;
}

node *insert(int coeff,int row,node *head){
	node *new = create(coeff,row);
	if(head == NULL)
		return new;
	node *temp = head;
	while(temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	return head;
}

void display(node *head){
	if(head == NULL){
		printf("Empty list\n");
		return;
	}
	node *temp = head;
	while(temp)
	{
		printf("Coeff=%d exp(y)=%d\n",temp->coeff,temp->row);
		temp = temp->next;
	}
}

node **init(node **head,int n){
	int i;
	head = (node **)malloc(sizeof(node *) * n);
	for(i=0;i<n;i++){
		head[i] = NULL;
	}
	return head;
}


node **add(node **sum,node **p1,node *p2,int n1,int n2)
{
	sum = init(sum,max(n1,n2));
	
}


int main()
{
	printf("Usage:\ndegree of first polynomial\nnumber of terms in the first polynomial\nEnter coefficients in the format of \"Coeffiecient exponent(x) exponent(y)\"\nDo the same for the second polynomial\n");
	int n1,t1,n2,t2;
	scanf("%d %d",&n1,&t1);
	node **p1,**p2;
	p1 = init(p1,n1);
	p2 = init(p2,n2);
	int coeff,x,y;
	while(t1--)
	{
		scanf("%d %d %d",&coeff, &x, &y);
		p1[x] = insert(coeff,y,p1[x]);
	}
	for(int i=0;i<n1;i++)
		display(p1[i]);
	scanf("%d %d",&n2,&t2);
	while(t2--)
	{
		scanf("%d %d %d",&coeff, &x, &y);
		p2[x] = insert(coeff,y,p2[x]);
	}
	for(int i=0;i<n2;i++)
		display(p2[i]);
	node **sum;
	sum = add(sum,p1,p2,n1,n2);
	
	return 0;
}