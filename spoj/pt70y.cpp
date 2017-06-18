//Shounak Dey
#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define PB push_back
#define MK make_pair 

void dfs(vector<int> &v,vector< vector<int> > adj,int start)
{
	if(v[start]>0)
	{
		v[start]=2;
		return;
	}
	v[start]=1;
	for(int i=0;i<adj[i].size();i++)
		dfs(v,adj,adj[start][i]);
	return;
}

int main()
{	
	int n,m;
	cin >> n >> m;
	vector<int> v(n,0);
	vector< vector<int> > adj;
	int x,y;
	vector<int> temp;
	for(int i=0;i<n;i++)
		adj.PB(temp);
	for(int i=0;i<m;i++)
	{
		cin >> x >> y;
		adj[x-1].PB(y-1);
		adj[y-1].PB(x-1);
	}
	dfs(v,adj,0);
	int flag=0;
	for(int i=0;i<n;i++)
	{
		if(v[i]==0)
		{
			flag=1;
			break;
		}
		else if(v[i]==2)
			flag=1;
	}
	for(int i=0;i<n;i++)
		cout << v[i] << " ";
	cout << endl;
	if(flag)
		cout << "NO" << endl;
	else
		cout << "YES" << endl; 
	return 0;
}

