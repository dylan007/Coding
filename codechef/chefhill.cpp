#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	int q;
	cin >> q;
	int max=0,x,y,i;
	while(q--)
	{
		cin >> x >> y;
		x--;
		y--;
		for(i=(x+1);i<=(y-1);i++)
		{
			if(a[x]<a[i])
				break;
		}
		if(i!=y)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	return 0;
}
