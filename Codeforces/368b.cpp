//Shounak Dey
#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define PB push_back
#define MK make_pair 

int main()
{	
	int n,m;
	cin >> n >> m;
	vector<int> visited(100001,0);
	vector<int> x(n);
	vector<int> dis(n,0);
	dis[n-1] = 1;
	for(int i=0;i<n;i++)
		cin >> x[i];
	visited[x[n-1]]=1;
	for(int i=(n-2);i>=0;i--)
	{
		if(!visited[x[i]])
		{
			visited[x[i]]=1;
			dis[i] = dis[i+1]+1;
		}
		else
			dis[i] = dis[i+1];
	}
	int y;
	while(m--)
	{
		cin >> y;
		cout << dis[y-1] << endl;
	}
	return 0;
}

