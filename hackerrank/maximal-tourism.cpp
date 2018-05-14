#include<bits/stdc++.h>

using namespace std;

int find(vector<int> p,int x)
{
	if(p[x] == x)
		return x;
	else
		return find(p,p[x]);
}

void un(vector<int>& p,int x,int y)
{
	int a,b;
	a = find(p,x);
	b = find(p,y);
	p[a] = b;
}

int main()
{
	int n,m,x,y;
	cin >> n >> m;
	vector<int>parent;
	for(int i=0;i<n;i++)
		parent.push_back(i);
	for(int i=0;i<m;i++)
	{
		cin >> x >> y;
		un(parent,x,y);
	}
	for(int i=0;i<n;i++)
		parent[i] = find(parent,parent[i]);
	sort(parent.begin(),parent.end());
	std::set<int> par(parent.begin(), parent.end());
	int c,M=-1,ans=-1;
	set<int>::iterator iter;
	for(iter=par.begin(); iter!=par.end();iter++)
	{
		c = count(parent.begin(),parent.end(),(*iter));
		if(c>M)
			M = c;
	}
	cout << M << endl;
	return 0;
}

