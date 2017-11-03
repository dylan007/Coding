#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef struct node
{
	int vals[2*MAX];
	int f[2],r[2];
}cq;

void push(cq *a,int m)
{
	if(a->f[m]<0 && a->r[m]<0)
	{
		a->f[m] = 0;
		a->r[m] = 0;
	}
	else
	{
		if(a->r[m] == (MAX-1))
			a->r[m] = 0;
		else
			a->r[m] ++;
	}
	scanf("%d",&(a->vals[m*MAX + a->r[m]]));
	return;
}

void pop(cq *a,int m)
{
	if(a->f[m]<0 && a->r[m]<0)
		printf("The selected queue is empty\n");
	else
	{
		printf("%d\n",a->vals[a->f[m]]);
		if(a->f[m] == a->r[m])
		{
			a->f[m] = -1;
			a->r[m] = -1;
		}
		else
			a->f[m] = (a->f[m]+1)%MAX;
	}
	return;
}


void display(cq *a,int m)
{
	int i=0;
	//printf("%d %d",a->f[m],a->r[m]);
	if(a->f[m]<0 && a->r[m]<0)
	{
		printf("Queue is empty\n");
		return;
	}
	if(a->f[m] <= a->r[m])
	{
		for(i=a->f[m];i<=a->r[m];i++)
			printf("%d ",a->vals[m*MAX + i]);
	}
	else
	{
		for(i=a->f[m];i<(m*MAX + MAX);i++)
			printf("%d ",a->vals[m*MAX + i]);
		for(i=0;i<=a->r[m];i++)
			printf("%d ",a->vals[m*MAX + i]);
	}
	printf("\n");
	return;
}

int main()
{
	cq a;
	a.f[1] = a.f[0] = -1;
	a.r[0] = a.r[1] = -1;
	int input,c;
	while(1)
	{
		scanf("%d %d",&input,&c);
		if(input > 3)
			break;
		if(input == 1)
			push(&a,c-1);
		else if(input == 2)
			pop(&a,c-1);
		else
			display(&a,c-1);
	}
	return 0;
}