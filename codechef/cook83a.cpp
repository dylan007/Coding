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
	int T;
	cin >> T;
	while(T--)
	{
		string a;
		cin >> a;
		int c1=(a[0]=='D'),c2=(a[0]=='U'),curr=(a[0]=='D');
		for(int i=1;i<a.length();i++)
		{
			if(curr==0 && a[i]=='D')	
			{
				curr=1;
				c1++;
			}
			else if(curr==1 && a[i]=='U')
			{
				curr=0;
				c2++;
			}
		}
		cout << min(c1,c2) << endl;
	}
	return 0;
}

