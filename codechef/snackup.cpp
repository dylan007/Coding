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
		cout << n << endl;
		REP(i,0,n)
		{
			cout << n << endl;
			int x,y;
			x = i+1;
			y = i+2;
			if(y>n)
				y=1;
			REP(j,0,n)
				cout << j+1 << " " << x << " " << y << endl;
		}
	}
	return 0;
}

