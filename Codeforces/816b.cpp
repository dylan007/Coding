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
	int n,k,q,x,y;
	cin >> n >> k >> q;
	vector<int> c(200100,0);
	int m = INT_MAX,M = INT_MIN;
	REP(i,0,n)
	{
		cin >> x >> y;
		c[x]++;
		c[y+1]--;
		m = min(x,m);
		M = max(y,M);
	}
	vector<int> dp(200100,0);
	REP(i,1,200100)
	{
		c[i] += c[i-1];
		dp[i] += (c[i]>=k);
		dp[i] += dp[i-1];
	}
	REP(i,0,q)
	{
		cin >> x >> y;
		cout << dp[y]-dp[x-1] << endl;
	}
	return 0;
}

