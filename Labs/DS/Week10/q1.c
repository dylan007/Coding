#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *left,*right;
}node;

node* new(int data)
{
	node *head = (node *)malloc(sizeof(node));
	head->data = data;
	head->left = head->right = NULL;
	return head;
}

node* insert(node *head,int data)
{
	if(head == NULL)
		return new(data);
	if(data>=head->data)
		head->right = insert(head->right,data);
	else
		head->left = insert(head->left,data);
	return head;
}

node* search(node *head,int data)
{
	if(head == NULL)
		return NULL;
	if(head->data == data)
		return head;
	if(head->data > data)
		return search(head->left,data);
	else
		return search(head->right, data);
}

void inorder(node *head)
{
	if(head==NULL)
		return;
	inorder(head->left);
	printf("%d ",head->data);
	inorder(head->right);
	return;
}

void preorder(node *head)
{
	if(head == NULL)
		return;
	printf("%d ",head->data);
	preorder(head->left);
	preorder(head->right);
}

void postorder(node *head)
{
	if(head == NULL)
		return;
	postorder(head->left);
	postorder(head->right);
	printf("%d ", head->data);
}

int main()
{
	node *head = NULL;
	int x,n;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&x);
		head = insert(head,x);
	}
	printf("Inorder : ");
	inorder(head);
	printf("\n");
	printf("Preorder : ");
	preorder(head);
	printf("\n");
	printf("Postorder : ");
	postorder(head);
	printf("\n");
	int q;
	printf("Enter number of queries\n");
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&x);
		if(search(head,x) == NULL)
			printf("Not Found\n");
		else
			printf("Found\n");
	}
	return 0;
}