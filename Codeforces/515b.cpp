#include<bits/stdc++.h>

using namespace std;

int gcd(int x,int y)
{
	return (x==0)?y:gcd(y%x,x);
}

int main()
{
	int n,m,b,g,G;
	cin >> n >> m;
	G = gcd(n,m);
	int state[n];
	memset(state,0,4*n);
	cin >> b;
	int x;
	for(int i=0;i<b;i++)
	{
		cin >> x;
		state[x%G] = 1;
	}
	cin >> g;
	for(int i=0;i<g;i++)
	{
		cin >> x;
		state[x%G] = 1;
	}
	int f=0;
	for(int i=0;i<G;i++)
	{
		if(state[i]==0)
			f=1;
	}
	if(f==1)
		cout << "No\n";
	else
		cout << "Yes\n";
	return 0;
}
