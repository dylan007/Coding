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
	READ(n);
	READ(m);
	READ(k);
	vector<int> hol(n,0);
	int x;
	for(int i=0;i<m;i++)
	{
		READ(x);
		hol[x-1]++;
	}
	int flag=0,pos=0,y;
	for(int i=0;i<k;i++)
	{
		if(hol[pos])
			flag=1;
		READ(x);
		READ(y);
		x--;
		y--;
		if(pos==x && !flag)
			pos = y;
		else if(pos==y && !flag)
			pos = x;
	}
	printf("%d\n",pos+1);
	return 0;
}

