#include<bits/stdc++.h>

using namespace std;


int find(vector<int> x,int c)
{
	if(x[c]==-1)
		return c;
	return find(x,x[c]);
}

int main()
{
	int n,m;
	cin >> n >> m;
	vector<int> x(n,-1);
	int a,b,flag=0;
	for(int i=0;i<m;i++)
	{
		cin >> a >> b;
		if(find(x,a)==find(x,b))
			flag=1;
		x[find(x,a)] = find(x,b);
	}
	if(flag)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
	return 0;
}