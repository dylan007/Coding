//Shounak Dey
#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define PB push_back

int main()
{
	int n,x;
	cin >> n;
	vector<int> a;
	for(int i=0;i<n;i++)
	{
		cin >> x;
		if(x)
			a.PB(i);
	}
	int count=(a.size()>0);
	for(int i=1;i<a.size();i++)
		count += min(2,a[i]-a[i-1]);
	cout << count << endl;
	return 0;
}

