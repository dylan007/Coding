#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct pq{
	int vals[MAX][2];
	int front,rear;
}pq;

int isFull(pq *p)
{
	if(p->front==0 && p->rear==(MAX-1))
		return 1;
	return 0;
}

void enqueue(pq *p,int data,int prio)
{
	if(isFull(p))
		return;
	int pos=0;
	if(p->front==-1 || p->rear==-1)
	{
		p->front = 0;
		p->rear = 0;
	}
	else
	{
		int i;
		for(i=p->front;i<p->rear;i++)
			if(p->vals[i][1]>prio) break;
		pos = i;
		//printf("%d\n",pos);
		for(i=(p->rear-1);i>=pos;i--)
		{	
			p->vals[i+1][0] = p->vals[i][0];
			p->vals[i+1][1] = p->vals[i][1];
		}
	}
	p->vals[pos][0] = data;
	p->vals[pos][1] = prio;
	p->rear = (p->rear+1)%MAX;
	return;
}

void dequeue(pq *p)
{
	if(p->front==-1 && p->rear==-1)
	{
		printf("Queue is empty\n");
		return;
	}
	printf("%d %d\n",p->vals[p->front][0],p->vals[p->front][1]);
	p->front++;
	if(p->front>=MAX)
	{
		p->front = -1;
		p->rear = -1;
	}
	return;
}

void display(pq p)
{
	int i;
	for(i=p.front;i<p.rear;i++)
		printf("%d %d\n",p.vals[i][0],p.vals[i][1]);
	printf("\n\n");
	return;
}

int main()
{
	pq p;
	p.front = -1;
	p.rear = -1;
	int input,d,pr;
	scanf("%d",&input);
	while(input<=3)
	{
		if(input==1)
		{
			scanf("%d %d",&d,&pr);
			enqueue(&p,d,pr);
		}
		else if(input == 2)
			dequeue(&p);
		else
			display(p);
		scanf("%d",&input);
	}
	return 0;
}