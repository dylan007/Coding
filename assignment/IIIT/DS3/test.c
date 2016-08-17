/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 16 April 2015 09:29:24  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shounak Dey (), dylandey1996@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include<stdio.h>
#include<limits.h>
#define maxVertices 100
#define  infinity 1000010000
typedef struct Node
{
        int vertex,distance;
}Node;
Node heap[1000000];

int seen[maxVertices];
int heapSize;

void Init()
{
        heapSize = 0;
        heap[0].distance = -INT_MAX;
        heap[0].vertex  = -1;
}

void Insert(Node element)
{
        heapSize++;
        heap[heapSize] = element; /*Insert in the last place*/
        int now = heapSize;
        while(heap[now/2].distance > element.distance) 
        {
                heap[now] = heap[now/2];
                now /= 2;
        }
        heap[now] = element;
}
Node DeleteMin()
{
        Node minElement,lastElement;
        int child,now;
        minElement = heap[1];
        lastElement = heap[heapSize--];
        for(now = 1; now*2 <= heapSize ;now = child)
        {
                child = now*2;
                if(child != heapSize && heap[child+1].distance < heap[child].distance ) 
                {
                        child++;
                }
                if(lastElement.distance > heap[child].distance)
                {
                        heap[now] = heap[child];
                }
                else 
                {
                        break;
                }
        }
        heap[now] = lastElement;
        return minElement;
}
int main()
{
        int graph[maxVertices][maxVertices],size[maxVertices]={0},distance[maxVertices]={0},cost[maxVertices][maxVertices];
        int vertices,edges,weight;
        int iter;
        scanf("%d%d",&vertices,&edges);
        int from,to;
        for(iter=0;iter<edges;iter++)
        {
                scanf("%d%d%d",&from,&to,&weight);
                assert(from>=0 && from<vertices);
                assert(to>=0 && to<vertices);
                graph[from][size[from]] = to;
                cost[from][size[from]] = weight;
                size[from]++;
        }
        int source;
        scanf("%d",&source);
        Node temp;
        for(iter=0;iter<vertices;iter++)
        {
                if(iter==source)
                {
                        temp.distance = 0;
                        distance[0]=0;
                }
                else
                {
                        temp.distance = infinity;
                        distance[iter]= infinity;
                }
                temp.vertex = iter;
                Insert(temp);
        }
        while(heapSize)
        {
                Node min = DeleteMin();
                int presentVertex = min.vertex;
                if(seen[presentVertex])
                {
                        continue;
                }
                seen[presentVertex] = 1;
                for(iter=0;iter<size[presentVertex];iter++)
                {
                        int to = graph[presentVertex][iter];
                        if(distance[to] > distance[presentVertex] + cost[presentVertex][iter])
                        {
                                distance[to] = distance[presentVertex] + cost[presentVertex][iter];
                                temp.vertex = to;
                                temp.distance = distance[to];
                                Insert(temp);
                        }
                }
        }
	int dest;
	scanf("%d",&dest);
        printf("%d\n",distance[dest]);
        return 0;
}
