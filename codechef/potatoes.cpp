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

void seive(vector<int> &primes,vector<int> v)
{
	for(int i=2;i<3100;i++)
	{
		if(!v[i])
		{
			primes.PB(i);
			for(int j=2*i;j<3100;j+=i)
				v[j] = 1;
		}
	}
}	


int main()
{
	vector<int> primes,v(3100,0);
	seive(primes,v);
	TESTCASE
	{
		int x,y;
		cin >> x >> y;
		x += y;
		for(int i=0;i<primes.size();i++)
		{
			if(primes[i]>x)
			{
				cout << primes[i]-x << endl;
				break;
			}
		}
	}
	return 0;
}

