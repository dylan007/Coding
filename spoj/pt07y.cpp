#include<bits/stdc++.h>

using namespace std;

int find(int parent,int x)
{
	if(parent[x] == x)
		return x;
	else
		return find(parent,parent[x]);
}

void un(vector<int> parent, int x, int y)
{
	int a,b;
	a = find(parent,x);
	b = find(parent,y);
	parent[a] = b;
}

int main()
{
	int x,y,n,m;
	cin >> n >> m;
	vector<int> parent(n,-1);
	for(int i=0;i<m;i++)
	{
		cin >> x >> y;
		un(parent,x,y);
	}
	return 0;
}
