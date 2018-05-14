#include<bits/stdc++.h>

using namespace std;

int main()
{
	int l;
	cin >> l;
	string a;
	cin >> a;
	int c1=0,c0=0;
	for(int i=0;i<l;i++)
	{
		c1 += (a[i]=='1');
		c0 += (a[i]=='0');
	}
	cout << abs(c1-c0) << endl;
	return 0;
}
