#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	int val[100];
	int top;
}stack;

void push(stack *a,int x)
{
	a->top ++;
	a->val[a->top] = x;
	return;
}

int pop(stack *a)
{
	if(a->top <0)
		return -1;
	int x = a->val[a->top];
	a->top --;
	return x;
}

int check(stack rev,char s[],int l)
{
	int i,x;
	for(i=0;i<(l/2);i++)
		push(&rev,(int)s[i]);	
	i = (l/2) + l%2;
	for(;i<l;i++)
	{
		x = pop(&rev);
		if(x<0)
			return 1;
		if(x != (int)s[i])
			return 1;
	}
	return 0;
}

int main()
{
	stack rev;
	rev.top = -1;
	char s[100];
	scanf("%s",s);
	int l=strlen(s);
	if(check(rev,s,l))
		printf("Not a palindrome\n");
	else
		printf("Palindrome\n");
	return 0;
}