#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max(a,b) (a>b?a:b)


typedef struct node{
	int data;
	struct node *left,*right;
}node;

typedef struct stack{
	node* data;
	struct stack *next;
}stack;

stack *cr(node* data){
	stack *new = (stack *)malloc(sizeof(stack));
	new->data = data;
	new->next = NULL;
	return new;
}

stack *push(stack *head,node* data){
	if(data == NULL) return head;
	if(head == NULL) return cr(data);
	stack *temp;
	temp = cr(data);
	temp->next = head;
	return temp;
}

stack *pop(stack *head){
	stack *temp = head->next;
	free(head);
	return temp;
}

int isEmpty(stack *head){
	return head==NULL;
}

node *create(int data){
	node *new = (node *)malloc(sizeof(node));
	new->data = data;
	new->left = new->right = NULL;
	return new;
}

node *insert(node *head,int data){
	if(head==NULL)
		return create(data);
	if(head->data < data){
		if(head->right)
		{ 
			head->right = insert(head->right,data);
			return head;
		}
		else{
			head->right = create(data);
			return head;
		}
	}
	else
	{
		if(head->left){
			head->left = insert(head->left,data);
			return head;
		}
		else{
			head->left = create(data);
			return head;
		}
	}
}

void inorder(node *head){
	if(head == NULL) return;
	inorder(head->left);
	printf("%d ",head->data);
	inorder(head->right);
	return;
}

void preorder(node *head){
	if(head == NULL) return;
	printf("%d ",head->data);
	preorder(head->left);
	preorder(head->right);
	return;
}

void postorder(node *head){
	if(head==NULL) return;
	postorder(head->left);
	postorder(head->right);
	printf("%d ",head->data);
	return;
}

int height(node *head){
	if(head == NULL)
		return 0;
	return 1 + max(height(head->left),height(head->right));
}

void initer(node *head){
	stack *s;
	s = NULL;
	node *curr = head;
	while(1){
		if(curr != NULL){
			s = push(s,curr);
			curr = curr->left;
		}
		else{
			if(isEmpty(s))
				return;
			curr = s->data;
			printf("%d ",curr->data);
			s = pop(s);
			curr = curr->right;
		}
	}
}

void preiter(node *head){
	stack *s;
	s = NULL;
	s = push(s,head);
	while(1){
		if(isEmpty(s))
			return;
		printf("%d ",s->data->data);
		node *temp = s->data;
		s = pop(s);
		s = push(s,temp->right);
		s = push(s,temp->left);
	}
}

void postiter(node *head){
	stack *s1,*s2;
	s1 = NULL;
	s2 = NULL;
	s1 = push(s1,head);
	while(!isEmpty(s1)){
		push(s2,s1->data);
		s1 = pop(s1);
		push(s1,s2->data->left);
		push(s1,s2->data->right);
	}
	while(s2)
	{
		printf("%d ",s2->data->data);
		s2 = s2->next;
	}
	printf("\n");
	return;
}

void levelorder(node *head){
	
}

int main()
{
	int n;
	scanf("%d",&n);
	int x;
	node *head;
	head = NULL;
	while(n--)
	{
		scanf("%d",&x);
		head = insert(head,x);
	}
	printf("Inorder\n");
	inorder(head);
	printf("\nPreorder\n");
	preorder(head);
	printf("\nPostorder\n");
	postorder(head);
	printf("\nHeight of the tree: %d\n",height(head));
	printf("Iterative Inorder\n");
	initer(head);
	printf("\n");
	printf("Preorder Iterative\n");
	preiter(head);
	printf("\n");
	printf("Postorder Iterative\n");
	postiter(head);
	printf("\n");
	return 0;
}
