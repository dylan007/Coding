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

ull sim(ull d,ull s,ull c,ull l)
{
	ull ans=s;
	d--;
	while(d-- && ans<l)
		ans += ans*c;
	return ans;
}

int main()
{
	TESTCASE
	{
		ull l,d,s,c;
		cin >> l >> d >> s >> c;
		if(sim(d,s,c,l)>=l)
			cout << "ALIVE AND KICKING" << endl;
		else
			cout << "DEAD AND ROTTING" << endl;
	}
	return 0;
}

