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
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		if(a==c)
		{
			if(d>b)
				cout << "up" << endl;
			else
				cout << "down" << endl;
		}
		else if(b==d)
		{
			if(c>a)
				cout << "right" << endl;
			else
				cout << "left" << endl;
		}
		else
			cout << "sad" << endl;
	}
	return 0;
}

