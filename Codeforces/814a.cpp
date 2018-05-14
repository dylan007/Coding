//Shounak Dey
#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define PB push_back
#define MK make_pair 
#define size(a) (int)(sizeof(a))

int main()
{
	int n,m;
	cin >> n >> m;
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin >> a[i];
	vector<int> b(m);
	for(int i=0;i<m;i++)
		cin >> b[i];
	sort(b.rbegin(),b.rend());
	int curr=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]==0)
		{
			a[i]=b[curr];
			curr++;
		}
	}
	vector<int> x = a;
	sort(x.begin(),x.end());
	//for(int i=0;i<n;i++)
//		cout << a[i] << " ";
//	cout << endl;
	if(x!=a)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}

