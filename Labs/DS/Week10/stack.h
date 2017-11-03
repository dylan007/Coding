#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
	int data;
	struct stack *next;
}stack;

stack *create(int data){
	stack *head = (stack *)malloc(sizeof(stack));
	head->next = NULL;
	head->data = data;
	return head;
}

stack *push(stack *head,int data){
	if(head == NULL)
		return create(data);
	stack *temp = head;
	head = create(data);
	head->next = temp;
	return head;
}

stack *pop(stack *head)
{
	stack *temp = head->next;
	printf("%d\n", head->data);
	free(head);
	return temp;
}

int isEmpty(stack *head)
{
	return head==NULL;
}