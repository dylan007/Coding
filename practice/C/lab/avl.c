#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max(int a,int b){
	return a>b?a:b;
}

typedef struct node{
	int data;
	struct node *left,*right;
}node;

node *create(int data){
	node *new = (node *)malloc(sizeof(node));
	new->data = data;
	new->left = new->right = NULL;
	return new;
}

int height(node *head){
	if(head == NULL)
		return 0;
	return 1 + max(height(head->left),height(head->right));
}

int balance(node *head){
	return height(head->left) - height(head->right);
}

node *leftRotate(node *head){
	node *T = head->right;
	head->right = head->right->left;
	T->left = head;
	return T;
}

node *rightRotate(node *head){
	node *T = head->left;
	head->left = head->left->right;
	T->right = head;
	return T;
}

node *insert(node *head,int data){
	if(head == NULL){
		head = create(data);
		return head;
	}
	if(head->data > data)
		head->left = insert(head->left,data);
	else
		head->right = insert(head->right,data);
	int bf = balance(head);
	// printf("Data:%d BF:%d\n",data,bf);
	if(bf>1 && data<head->left->data)
		return rightRotate(head);
	else if(bf<-1 && data>head->right->data)
		return leftRotate(head);
	else if(bf<-1 && data<head->right->data){
		head->right = rightRotate(head->right);
		return leftRotate(head);
	}else if(bf>1 && data>head->left->data){
		head->left = leftRotate(head->left);
		return rightRotate(head);
	}
	return head;
}

void recBal(node *head){
	if(head == NULL)
		return;
	printf("%d %d\n",head->data,balance(head));
	recBal(head->left);
	recBal(head->right);
}

void preorder(node *head){
	if(head==NULL) return;
	printf("%d ",head->data);
	preorder(head->left);
	preorder(head->right);
	return;
}

int main(){
	int n;
	scanf("%d",&n);
	int x;
	node *head = NULL;
	while(n--){
		scanf("%d",&x);
		head = insert(head,x);
		// recBal(head);		
		// printf("height: %d\n",height(head));
		// preorder(head);
		// printf("\n");
	}
	preorder(head);
	recBal(head);
	return 0;
}