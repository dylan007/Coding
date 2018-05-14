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
		int n,b;
		cin >> n >> b;
		if(n==2)
		{
			if(b==1)
				cout << "YES\n1 2\n";
			else
				cout << "NO\n";
		}
		else
		{
			if(b<=(n/4))
			{
				cout << "YES\n";
				for(int i=0;i<2*b;i++)
					cout << i+1 << " " << i+2 << "\n";
				for(int i=max(1,2*b+1);i<n;i++)
					cout << "1 " << i+1 << "\n";
			}
			else
				cout << "NO\n";
		}	
	}
	return 0;
}

