#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n = 100000;
	int arr[n];
	arr[0] = 0;
	for(int i=1;i<n;i++)
		arr[i] = arr[i-1]^i;
	int q;
	cin >> q;
	while(q--)
	{
		int x,y;
		cin >> x >> y;
		x = arr[y]^arr[x-1];
		cout << x << endl;
	}
	return 0;
}
