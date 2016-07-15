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

int n,m;
edge edges[100000];
int parents[100000];

int cmpfunc(const void *a,const void *b)
{
	const struct edge *elem1 = a;
	const struct edge *elem2 = b;
	return elem1->w - elem2->w;
}

int find(int x)
{
	if(parents[x]==-1)
		return x;
	return parents[x] = find(parents[x]);
}
	
void un(int x,int y)
{
	parents[x] = y;
}

long long int ans=0;

void kruskal()
{
	int i;
	for(i=0;i<n;i++)
		parents[i] = -1;
	int e=0;
	i=0;
	while(e < (n-1))
	{
		int x = find(edges[i].u);
		int y = find(edges[i].v);

		if(x != y)
		{
			ans += (long long int)edges[i].w;
			//printf("%d %d\n",edges[i].u,edges[i].v);
			un(x,y);
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
