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

int check(char a)
{
	if(a=='_')
		return 1;
	else if(a>='a' && a<='z')
		return 3;
	else if(a>='A' && a<='Z')
		return 2;
	else
		return 4;
}


int main()
{
	int T;
	cin >> T;
	string low,high="";
	cin >> low;
	for(int i=0;i<26;i++)
		high += low[i]+'A'-'a';
	while(T--)
	{
		string in;
		cin >> in;
		for(int i=0;i<in.length();i++)
		{
			switch(check(in[i]))
			{
				case 1:
					cout << " ";
					break;
				case 2:
					cout << high[in[i]-'A'];
					break;
				case 3:
					cout << low[in[i]-'a'];
					break;
				case 4:
					cout << in[i];
					break;
			}
		}
		cout << endl;
	}
	return 0;
}

