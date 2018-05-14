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
	int n;
	cin >> n;
	vector< pair<int,int> > d;
	int x,y;
	for(int i=0;i<n;i++)
	{
		cin >> x >> y;
		d.PB(MK(x,y));
	}
	sort(d.begin(),d.end());
	int curr=0;
	for(int i=0;i<n;i++)
	{
		if(min(d[i].first,d[i].second) >= curr)
			curr = min(d[i].first,d[i].second);
		else
			curr = max(d[i].first,d[i].second);
	}
	cout << curr << endl;
	return 0;
}

