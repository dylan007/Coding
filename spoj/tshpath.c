/*
 * =====================================================================================
 *
 *       Filename:  tshpath.c
 *
 *    Description:  Implement Dijkstra on an adjacency list
 *
 *        Version:  1.0
 *        Created:  Wednesday 01 April 2015 09:34:20  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shounak Dey (), dylandey1996@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>

typedef struct elem
{
	int vertex;
	int weight;
}elem;

typedef struct Q
{
	int vertex;
	int dist;
}Q;

elem *adj[10000];

int hash(char inp[],int n)
{
	int len;
	len = strlen(inp);
	int i;
	unsigned long long int ans=0,temp;
	for(i=0;i<len;i++)
	{
		temp = ((inp[i]-'a')*((int)(pow(26,i))))%n;
		ans = ((ans%n)+temp)%n;
	}
	return (int)ans;
}

void insert(Q *heap,int x,int y,int index)
{
	Q temp;
	printf("insertion index = %d vertex = %d dist = %d\n",index,x,y);
	temp.vertex = x;
	temp.dist = y;
	heap[index] = temp;
	while((heap[index].dist < heap[(index-1)/2].dist) && index>0)
	{
		temp = heap[index];
		heap[index] = heap[(index-1)/2];
		heap[(index-1)/2] = temp;
		index = (index-1)/2;
	}
}

Q delete(Q *heap,int index)
{
	Q ans;
	Q temp;
	ans = heap[0];
	heap[0] = heap[index];
	int count = index-1;
	while((heap[index].dist > heap[2*index+1].dist) || (heap[index].dist > heap[2*index+2].dist) && index<=count)
	{
		if(heap[2*index+1].dist > heap[2*index+2].dist)
		{
			temp = heap[2*index+1];
			heap[2*index+1]=heap[index];
			heap[index]=temp;
			index=2*index+1;
		}
		else
		{
			temp = heap[2*index+2];
			heap[2*index+2] = heap[index];
			heap[index]=temp;
			index = 2*index+2;
		}
	}

}
	
int dijkstra(int u,int v,int neigh[],int n)
{
	int distance[n];
	int i;
	distance[u]=0;
	Q heap;
	int count=0;
	for(i=0;i<n;i++)
	{
		if(i!=u)
			distance[i]=INT_MAX;
		insert(&heap,i,INT_MAX,count++);
	}
	Q temp;
	while(count > 0)
	{
		temp = delete(&heap,count-1);
		count--;
		for(i=0;i<neigh[temp.vertex];i++)
		{
			int alt = distance[temp.vertex] + adj[temp.vertex][i].weight;
			if(alt < distance[adj[temp.vertex][i].vertex - 1])
			{
				distance[adj[temp.vertex][i].vertex - 1] = alt;
				insert(&heap,adj[temp.vertex][i].vertex-1,alt,count++);
			}
		}
	}
	return distance[v];
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d%*C",&n);
		char cities[n][20];
		int i,n_neigh[n];
		int p;
		for(i=0;i<n;i++)
		{
			char inp[20];
			scanf("%s%*C",inp);
			int index = hash(inp,n);
			strcpy(cities[index],inp);
			scanf("%d",&p);
			adj[index] = (elem *)malloc(8*p);
			int j,x,y;
			n_neigh[index] = p;
			for(j=0;j<p;j++)
			{
				scanf("%d %d%*C",&x,&y);
				adj[index][j].vertex = x-1;
				adj[index][j].weight = y;
			}
		}
		for(i=0;i<n;i++)
		{
			int j;
			for(j=0;j<n_neigh[i];j++)
				printf("%s %d %d\n",cities[i],adj[i][j].vertex,adj[i][j].weight);
			printf("\n");
		}
		int q;
		scanf("%d",&q);
		while(q--)
		{
			char city1[20],city2[20];
			int index1 = hash(city1,n);
			int index2 = hash(city2,n);
			printf("%d\n",dijkstra(index1,index2,n_neigh,n));
		}

	}
	return 0;
}
