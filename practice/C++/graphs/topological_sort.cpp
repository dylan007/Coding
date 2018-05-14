/*Given an acyclic directed graph , print the topological sort of the graph
The element adj[i][j] represents an edge from vertex i to vertex j
The function topsort() simulates the topological sorting.The function findNewVertex() finds a new vertex with indegree 0.
The array visited keeps check of the vertices visited.
*/

#include<bits/stdc++.h>

using namespace std;

int adj[1000][1000];
int visited[1000]={0};

int findNewVertex(int n)
{
	int i,j,f=0;
	for(i=0;i<n;i++)
	{
		f=0;	
		for(j=0;j<n;j++)
		{
			if(adj[j][i]!=0)
				f++;
		}
		if(f==0 && visited[i]==0)
			return i;
	}
	return -1;
}

void topsort(int n)
{
	int k,j,i,V;
	for(k=0;k<n;k++)
	{
		V = findNewVertex(n);
		visited[V]=1;
		if(V<0)
		{
			cout << "The given graph has a cycle\n";
			return;
		}
		cout << V+1 << " ";
		for(i=0;i<n;i++)
			adj[V][i]=0;
	}
}

int main()
{
	cout << "Enter the number of vertices\n";
	int n;
	cin >> n;
	cout << "Enter the adjacency matrix\n";
	int i,j;
	int adj[n][n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cin >> adj[i][j];
	}
	topsort(n);
	cout << endl;
	return 0;
}
