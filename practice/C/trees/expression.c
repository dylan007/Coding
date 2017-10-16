#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a,b) (a>b?a:b)


typedef struct node{
	char data;
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
	if(head == NULL) return NULL;
	stack *temp = head->next;
	free(head);
	return temp;
}

int isEmpty(stack *head){
	return head==NULL;
}

node *create(char data){
	node *new = (node *)malloc(sizeof(node));
	new->data = data;
	new->left = new->right = NULL;
	return new;
}

void inorder(node *head){
	if(head == NULL) return;
	inorder(head->left);
	printf("%d ",head->data);
	inorder(head->right);
	return;
}

void disp(stack *head){
	while(head){
		printf("%c ",head->data->data);
		head = head->next;
	}
	return;
}

int main()
{
	char str[100000];
	scanf("%s%*c",str);
	stack *s;
	s = NULL;
	node *head;
	for(int i=0;i<strlen(str);i++){
		disp(s);
		printf("\n");
		if(str[i]>='0' && str[i]<='9'){
			s = push(s,create(str[i]));
		}
		else{
			node *t1,*t2;
			if(isEmpty(s))
				t1 = NULL;
			else
				t1 = s->data;
			s = pop(s);
			if(isEmpty(s))
				t2 = NULL;
			else
				t2 = s->data;
			s = pop(s);
			head = create(str[i]);
			head->left = t1;
			head->right = t2;
			s = push(s,head);
		}
	}
	inorder(s->data);
	return 0;
}