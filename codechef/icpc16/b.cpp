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
		int n;
		cin >> n;
		int x;
		int c=0;
		for(int i=0;i<n;i++)
		{
			cin >> x;
			c += (x!=1) && (x!=0);
		}
		if(c<=1)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}

