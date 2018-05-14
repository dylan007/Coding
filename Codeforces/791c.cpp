#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,k;
	cin >> n >> k;
	string names[100];
	for(int i = 0; i < n; ++i) {
		names[i] = "Aa";
		names[i][0] += i / 26;
		names[i][1] += i % 26;
	}
	for(int i=0;i<(n-k+1);i++)
	{
		string a;
		cin >> a;
		if(a[0] == 'N')
			names[i+k-1] = names[i];
	}
	for(int i=0;i<n;i++)
		cout << names[i] << " ";
	cout << endl;
	return 0;
}

