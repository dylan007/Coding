#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct pq{
	char vals[MAX][MAX];
	int front,rear;
}pq;

void pushback(pq *p,char *s)
{
	if(p->rear == (MAX-1))
		return;
	if(p->front==-1 && p->rear==-1)
	{
		p->front = 0;
		p->rear = 0;
	}
	strcpy(p->vals[p->rear],s);
	p->rear++;
	return;
}

void pushfront(pq *p,char *s)
{
	if(p->front == 0)
		return;
	if(p->front==-1 && p->rear==-1)
	{
		p->front = 0;
		p->rear = 0;
		strcpy(p->vals[p->front],s);
		return;
	}
	strcpy(p->vals[p->front-1],s);
	p->front--;
	return;
}

void popfront(pq *p)
{
	if((p->front==-1 && p->rear==-1) && (p->front>=MAX))
	{
		printf("Queue is empty\n");
		return;
	}
	printf("%s\n\n",p->vals[p->front++]);
}

void display(pq p)
{
	int i;
	for(i=p.front;i<p.rear;i++)
		printf("%s\n",p.vals[i]);
	printf("\n");
}

int main()
{
	pq p;
	p.front = -1;
	p.rear = -1;
	int input;
	char s[MAX];
	while(input <= 4)
	{
		if(input==1)
		{
			getchar();
			scanf("%s",s);
			pushback(&p,s);
		}
		else if(input ==2)
		{
			getchar();
			scanf("%s",s);
			pushfront(&p,s);
		}
		else if(input == 3)
			popfront(&p);
		else
			display(p);
		scanf("%d",&input);
	}
	return 0;
}