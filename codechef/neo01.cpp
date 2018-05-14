//Shounak Dey
#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define PB push_back
#define MK make_pair 

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		ll ps=0,ns=0,cp=0;
		ll x;
		vector<ll> val,p;
		for(int i=0;i<n;i++) 
		{
			cin >> x;
			val.PB(x);
			p.PB(x);
		}
		sort(val.rbegin(),val.rend());
		sort(p.rbegin(),p.rend());
		ll index=0,max=val[0];
		for(int i=1;i<n;i++)
		{
			val[i-1] /= i;
			val[i] += val[i-1];
			val[i] *= (i+1);
			val[i-1] *= i;
			if(max<=val[i])
			{
				max = val[i];
				index = i;
			}
		}
		//cout << endl;
		//for(int i=0;i<n;i++)
		//	cout << val[i] << endl;
		//cout << index << endl;
		for(int i=index+1;i<n;i++)
			max += p[i];
		cout << max << endl;
		//cout << ps*cp + ns << endl;
	}
	return 0;
}

