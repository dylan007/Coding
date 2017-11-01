#include <stdio.h>
#include <stdlib.h>
 
#define max(a,b) (a>b?a:b) //defined an inline max function

typedef struct node{
	int coeff;												//coefficient of x^a . y^b;
	int row;												//exponent of y
	struct node *next;										//linked list implementation
}node;

node *create(int coeff,int row)								//takes the coefficient and the exponent of y
{															//and returns the node.
	node *new = (node *)malloc(sizeof(node));
	new->coeff = coeff;
	new->row = row;
	return new;
}

node *insert(int coeff,int row,node *head){					//Insert into the list and return updated head address.
	node *new = create(coeff,row);							
	if(head == NULL)
		return new;											//return create return value if list is empty
	node *temp = head;
	while(temp->next != NULL)								//Traverse to the last element of the linked list.
		temp = temp->next;
	temp->next = new;
	return head;											//return updated head address.
}

void display(node *head,int column){						//display function for the linked list.
	if(head == NULL){
		printf("Empty list\n");
		return;
	}
	node *temp = head;
	while(temp)
	{
		printf("Coeff=%d exp(y)=%d exp(x)=%d\n",temp->coeff,temp->row,column);
		temp = temp->next;
	}
}

node **init(node **head,int n){								//Creates a polynomial. The polynomial is saved as an array of linked
	int i;													//lists. Row i corresponds to all terms with term x^i.y^a,
	head = (node **)malloc(sizeof(node *) * n);				// 0<= a <= degree of polynomial. Here we allocate space for each
	for(i=0;i<n;i++){										// array location and return this newly created polynomial.
		head[i] = NULL;
	}
	return head;
}

node *search(node *sum,int exp)								//Searches for the term with exponent of y equal to exp.
{															//returns that node address if found otherwise NULL.
	if(sum == NULL)
		return NULL;
	while(sum != NULL)
	{
		if(sum->row == exp)
			return sum;
		sum = sum->next;
	}
	return NULL;
}


node **add(node **sum,node **p1,node **p2,int n1,int n2)	//Main function which adds two polynomials. This returns the 
{															//final polynomial.
	sum = init(sum,max(n1,n2));								//initialising the resultant polynomial
	int i;																	
	node **temp;											//creating a temporary polynomial
	if(n1<n2){												//saving the smaller polynomial in p2 to simplify the code.
		temp = p1;											//swapping p1 and p2
		p1 = p2;
		p2 = temp;
		n1 = n1+n2;											//swapping n1 and n2
		n2 = n1-n2;
		n1 = n1-n2;
	}
	for(i=0;i<n1;i++)										//copying the larger polynomial to the resultant polynomial
	{
		node *t;
		t = p1[i];
		while(t!=NULL)
		{
			sum[i] = insert(t->coeff,t->row,sum[i]);
			t = t->next;
		}
		//display(sum[i],i);
	}
	for(i=0;i<n2;i++)										//Adding the smaller polynomial to the resultant polynomial.
	{
		node *t;
		t = p2[i];
		while(t!=NULL)
		{
			node *res = search(sum[i],t->row);				// Looks for a similar term in the resultant polynomial.
			if(res)											// If found , add the coefficient to the resultant polynomial.
				res->coeff += t->coeff;						
			else
				sum[i] = insert(t->coeff,t->row,sum[i]);	// Else insert this element into the resultant polynomial.
			t = t->next;
		}
		//display(sum[i],i);
	}
	/*for(i=0;i<n1;i++)
	{
		display(sum[i],i);
		printf("\n");
	}*/
	return sum;												// Return the final polynomial
}


int main()
{
	//printf("Usage:\ndegree of first polynomial\nnumber of terms in the first polynomial\nEnter coefficients in the format of \"Coeffiecient exponent(x) exponent(y)\"\nDo the same for the second polynomial\n");
	int n1,t1,n2,t2;
	printf("Enter the degree and number of terms in the first polynomial : ");
	scanf("%d %d",&n1,&t1);
	node **p1,**p2;
	n1++;
	n2++;
	p1 = init(p1,n1);
	p2 = init(p2,n2);
	int coeff,x,y;
	while(t1--)
	{
		scanf("%d %d %d",&coeff, &x, &y);
		p1[x] = insert(coeff,y,p1[x]);
	}
	//for(int i=0;i<n1;i++)
	//	display(p1[i]);
	printf("\n\nEnter the degree and number of terms in the second polynomial : ");
	scanf("%d %d",&n2,&t2);
	while(t2--)
	{
		scanf("%d %d %d",&coeff, &x, &y);
		p2[x] = insert(coeff,y,p2[x]);
	}
	//for(int i=0;i<n2;i++)
	//	display(p2[i]);
	printf("The sum of the given polynomials is: \n");
	node **sum;
	int i;
	sum = add(sum,p1,p2,n1,n2);
	for(i=0;i<max(n1,n2);i++)
		display(sum[i],i);
	return 0;
}
