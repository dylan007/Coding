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
		int n,m;
		cin >> n >> m;
		if(n&1)
			cout << m << endl;
		else
		{
			if(m<=2)
				cout << 2*m << endl;
			else if(m>2 && m<=6)
				cout << "4" << endl;
			else
				cout << 2*(m-6)+4 << endl;
		}
	}
	return 0;
}

