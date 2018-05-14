/*=======================
Author    : Shounak Dey
Filename  : cplay.cpp
=======================	*/

#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define PB push_back
#define MK make_pair 
#define SZ(a) (int)(sizeof(a))
#define F first
#define S second
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) for(int i=0;i<n;i++)
#define read(n) scanf("%d",&n)
#define readl(n) scanf("%lld",&n)
#define readul(n) scanf("%llu",&n);


#define SORTV(a) sort(a.begin(),a.end())
#define TEST int Test;cin >> Test;while(Test--)
#define gcd(a,b) __gcd(a,b)
#define ffs(a) __builtin_ffs(a) // find first set
#define clz(a) __builtin_clz(a) // count leading zeroes
#define ctz(a) __builtin_ctz(a) // count trailing zeroes
#define popc(a) __ builtin_popcount(a) // count set bits
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)


#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }

vector<string> split(const string& s, char c) {
	vector<string> v;
	stringstream ss(s);
	string x;
	while (getline(ss, x, c))
		v.emplace_back(x);
	return move(v);
}

void err(vector<string>::iterator it) {}
template<typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
	cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << '\n';
	err(++it, args...);
}

int fin(int c1,int c2,int s)
{
	int s1,s2;
	s1 = s/2 + 1;
	s2 = s/2 + s%2;
	//cout << s1 << " " <<  s2 << endl;
	if(c1 > c2)
	{
		if(c1-c2 > (5-s2))
			return 1;
	}
	if(c2 > c1)
	{
		if(c2-c1 > (5-s1))
			return 1;
	}
	return 0; 
}

int main()
{
	string a;
	while(cin >> a)
	{
		int c1=0,c2=0,i;
		for(i=0;i<10;i++)
		{
			if(i%2 == 0)
				c1 += a[i]-'0';
			else
				c2 += a[i]-'0';
			if(fin(c1,c2,i))
				break;
		}
		//cout << c1 << " " << c2 << " " << i << endl;
		if(c1!=c2)
		{
			if(c1 > c2)
				cout << "TEAM-A ";
			else
				cout << "TEAM-B ";
			cout << i+1 << endl;
		}
		else
		{
			for(i=10;i<20;i+=2)
			{
				c1 += a[i]-'0';
				c2 += a[i+1]-'0';
				if(c1!=c2)
					break;
			}
			if(c1>c2)
				cout << "TEAM-A " << i+2 << endl;
			else if(c2>c1)
				cout << "TEAM-B " << i+2 << endl;
			else
				cout << "TIE" << endl;
		}
	}
	return 0;
}
