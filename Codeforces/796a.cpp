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
	int n,m,k;
	cin >> n >> m >> k;
	int index=INT_MAX;
	int x;
	for(int i=1;i<=n;i++)
	{
		cin >> x;
		if(i!=m && x!=0 && x<=k)
			index = min(index,abs(i-m));
	}
	cout << index*10 << endl;
	return 0;
}

