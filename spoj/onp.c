#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stack
{
	char op;
	struct node *next;
}stack;

void push(stack *head,char inp)
{
	stack *new;
	while(head->next != NULL)
		head = head->next;
	new = (stack *)malloc(sizeof(stack));
	head->next = new;
	new->op = inp;
	new->next = NULL;

}

char pop(stack *head)
{
	char c;
	stack *prev;
	while(head->next != NULL)
	{
		prev = head;
		head = head->next;
	}
	c = head->op;
	prev->next = NULL;
	free(head);
	return c;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		stack *head;
		head = (stack *)malloc(sizeof(stack));
		head->next = NULL;
		char exp[400],c;
		scanf("%s",exp);
		int len = strlen(exp);
		int i,t;
		for(i=0;i<len;i++)
		{
			t = exp[i];
			if(t>=97 && t<=122)
				printf("%c",exp[i]);
			else
			{
				if(exp[i] == ')')
				{
					c = pop(head);
					while(c != '(')
					{
						printf("%c",c);
						c = pop(head);
					}
				}
				else
					push(head,exp[i]);
			}
		}
	}
	return 0;
}	
