#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct term{
	int coeff;//coefficient of a^x + b^x;
	int x;
	int y;
}term;

typedef struct node{
	term data;
	struct node *next;
}node;

term *create(int coeff,int x,int y){
	term *new = (term *)malloc(sizeof(term));
	new->coeff = coeff;
	new->x = x;
	new->y = y;
	return new;
}

node *init(term *x){
	node *new = (node *)malloc(sizeof(term));
	new->data = *x;
	new->next = NULL;
}

node *insert(int coeff,int x,int y,node *head){
	if(head == NULL)
		return init(create(coeff,x,y));
	node *temp = head;
	while(temp->next != NULL) temp=temp->next;
	temp->next = init(create(coeff,x,y));
	return head;
}

void printterm(term x){
	printf("%d %d %d\n",x.coeff,x.x,x.y);
}

node *getLast(node *head){
	while(head->next != NULL) head=head->next;
	return head;
}

void display(node *head)
{
	while(head)
	{
		printterm(head->data);
		head = head->next;
	}
	return;
}

int check(term *a,term *b)
{
	return (a->x == b->x)&&(a->y == b->y);
}

node *add(node *A,node *B){
	node *head = NULL;
	while(A){
		node *temp = B;
		head = init(A);
		while(temp){
			if(check(A,temp))
				
		}
	}
}

int main()
{
	int n;
	node *A = NULL;
	printf("Enter the number of terms in polynomial A :");
	scanf("%d",&n);
	printf("Enter the terms, in coeff exp(x) exp(y) format: \n");
	while(n--){
		int coeff,x,y;
		scanf("%d %d %d",&coeff,&x,&y);
		A = insert(coeff,x,y,A);
	}	
	node *B = NULL;
	printf("Enter the number of terms in polynomial B :");
	scanf("%d",&n);
	printf("Enter the terms, in coeff exp(x) exp(y) format: \n");
	while(n--){
		int coeff,x,y;
		scanf("%d %d %d",&coeff,&x,&y);
		B = insert(coeff,x,y,B);
	}
	display(A);
	display(B);
	node *S = NULL;
	S = add(A,B);
	display(S);
	return 0;
}