/*
 * =====================================================================================
 *
 *       Filename:  mst.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 09 April 2015 11:36:15  IST
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

typedef struct edge
{
	int u,v,w;
}edge;

typedef struct set
{
	int parent;
	int rank;
}set;

int n,m;
edge edges[100000];

int cmpfunc(const void *a,const void *b)
{
	const struct edge *elem1 = a;
	const struct edge *elem2 = b;
	return elem1->w - elem2->w;
}

int find(set parents[],int x)
{
	if(parents[x].parent != x)
		parents[x].parent = find(parents,parents[x].parent);
	return parents[x].parent;
}

void un(set parents[],int x,int y)
{
	int r1 = find(parents,x);
	int r2 = find(parents,y);
	if(parents[r1].rank > parents[r2].rank)
		parents[r1].parent = r2;
	else if(parents[r1].rank < parents[r2].rank)
		parents[r2].parent = r1;
	else
	{
		parents[r2].parent = r1;
		parents[r1].rank++;
	}
	//return &parents;
}

long long int ans=0;

void kruskal()
{
	set parents[n];
	int i;
	for(i=0;i<n;i++)
	{
		parents[i].parent = i;
		parents[i].rank = 0;
	}
	int e=0;
	i=0;
	while(e < (n-1))
	{
		int x = find(parents,edges[i].u);
		int y = find(parents,edges[i].v);

		printf("hello\n");
		if(x != y)
		{
			ans += (long long int)edges[i].w;
			printf("%d %d\n",edges[i].u,edges[i].v);
			un(parents,x,y);
			e++;
		}
		i++;
	}
}

int main()
{
	scanf("%d %d",&n,&m);
	int i;
	for(i=0;i<m;i++)
		scanf("%d %d %d",&edges[i].u,&edges[i].v,&edges[i].w);
	qsort(edges,m,sizeof(edge),cmpfunc);
	/*for(i=0;i<m;i++)
	{
		printf("%d %d %d\n",edges[i].u,edges[i].v,edges[i].w);
	}*/
	kruskal();
	printf("%lld\n",ans);
	return 0;
}
