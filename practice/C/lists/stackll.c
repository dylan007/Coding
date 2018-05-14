#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}stack;

stack *top;

void push(int x)
{
	stack *NEW;
	NEW = (stack *)malloc(sizeof(stack));
	NEW->data = x;
	NEW->next = top;
	top=NEW;
}

int pop()
{
	if(top == NULL)
		return -1;
	int x = top->data;
	top = top->next;
	return x;
}

int TOP()
{
	if(top == NULL)
		return -1;
	return top->data;
}

int main()
{
	int x;
	printf("1.push\n2.pop\n3.top\n4.exit\n");
	scanf("%d",&x);
	int f=0,t;
	while(x<4 && x>0)
	{
		switch(x)
		{
			case 1:
				printf("Enter the number\n");
				scanf("%d",&t);
				if(f==0)
				{
					top = (stack *)malloc(sizeof(stack));
					top->next=NULL;
					top->data = t;
					f=1;
				}
				else
					push(t);
				break;
			case 2:
				printf("%d\n",pop());
				break;
			case 3:
				printf("%d\n",TOP());
				break;
		}
		printf("1.push\n2.pop\n3.top\n4.exit\n");
		scanf("%d",&x);
	}
	return 0;
}
