#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct node
{
	int data;
	struct node *next;
}node;

int n;
node *heads[10000];
int visited[10000];

node *insert(int source,int x)
{
	if(heads[source]==NULL)
	{
		heads[source] = (node *)malloc(sizeof(node));
		heads[source]->next = NULL;
		heads[source]->data = x;
	}
	else
	{
		node *new;
		new = (node *)malloc(sizeof(node));
		new->next = heads[source];
		new->data = x;
		heads[source] = new;
	}
}

void print(int i)
{
	node *temp;
	temp = heads[i];
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void dfs(int x)
{
	int i;
	node *temp;
	temp = heads[x];
	visited[x] = 1;
	while(temp!=NULL)
	{
		if(visited[temp->data - 1]!=1)
			dfs(temp->data - 1);
		temp = temp->next;
	}
}

int main()
{
	printf("Enter the number of vertices in the graph : ");
	scanf("%d",&n);
	memset(heads,0,n*sizeof(node));
	memset(visited,0,n*sizeof(int));
	printf("Enter the number of edges in the graph : ");
	int edges;
	scanf("%d",&edges);
	int i;
	int x,y;
	for(i=0;i<edges;i++)
	{
		scanf("%d %d",&x,&y);
		insert(x-1,y);
		insert(y-1,x);
	}
	//for(i=0;i<n;i++)
	//	print(i);
	printf("Enter the nodes to check for a path : ");
	scanf("%d %d",&x,&y);
	dfs(x-1);
	if(visited[y-1] == 1)
		printf("Yes, a path exists between %d and %d\n",x,y);
	else
		printf("No, a path does not exist between %d and %d\n",x,y);
	return 0;
}
