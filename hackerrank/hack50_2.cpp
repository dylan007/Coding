//Shounak Dey
#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define PB push_back
#define MK make_pair 
#define SZ(a) (int)(sizeof(a))
#define F first
#define S second
#define REP(i,a,b) for(int i=a;i<b;i++)
#define READ(n) scanf("%d",&n)
#define READL(n) scanf("%lld",&n)
#define SORTV(a) sort(a.begin(),a.end())
#define TESTCASE int Test;cin >> Test;while(Test--)


int main()
{
	TESTCASE
	{
		ull n;
		cin >> n;
		ull m = (3*n)/2 + 2*(n&1);
		vector<ull> p(n);
		ull sum=0;
		for(ull i=0;i<n;i++)
		{
			cin >> p[i];
			sum += p[i];
		}
		if(sum < m)
			cout << "-1" << endl;
		else
		{
			if(n&1)
			{
				if(((n/2)&1) != (sum&1))
					cout << "-1" << endl;
				else
				{
					for(int i=0;i<(n-1);i++)
					{
						cout << (!(i&1))*2 + (i&1) << " ";
						sum -= (!(i&1))*2 + (i&1);
					}
					cout << sum << endl;
				}
			}
			else
			{
				if((((n/2)&1) != (sum&1)))	
					cout << "-1" << endl;
				else
				{
					for(int i=0;i<(n-1);i++)
					{
						cout << (!(i&1))*2 + (i&1) << " ";
						sum -= (!(i&1))*2 + (i&1);
					}
					cout << sum << endl;
				}
			}
		}
	}
	return 0;
}

