/*=======================
Author    : Shounak Dey
Filename  : prtition.cpp
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


string generate(ull n,ull x)
{
	string s = "";
	REP(i,n)
		s += "0";
	ull sum = (n*(n+1))/2 - x;
	ull t = n;
	if(sum%2)
		return "impossible";
	sum /= 2;
	while(sum && t>0)
	{
		//cout << t << " " << sum << endl;
		if(t>sum){
			s[sum-1] = '1';
			sum = 0;
			break;
		}
		else
		{
			s[t-1] = '1';
			sum -= t;
			t--;
		}
	}
	//cout << s << endl;
	if(s[x-1] == '1')
	{
		ull p1,p2;
		p1 = x-1;
		p2 = 1;
		ull flag=0;
		while(p1>p2)
		{
			if(s[p1-1]=='0' && s[p2-1]=='0')
			{
				flag=1;
				s[p1-1] = '1';
				s[p2-1] = '1';
				break;
			}
			p1--;
			p2++;
		}
		if(!flag)
		{
			for(ull i=x+1;i<n;i++)
			{
				if(s[i-1] == '1')
				{
					p2 = i-1;
					break;
				}
			}
			p1 = x+1;
			flag=0;
			ull temp = p2;
			while(p1<p2)
			{
				// cout << p1 << " " << p2 << endl;
				// cout << s[p1-1] << " " << s[p2-1] << endl;
				if(s[p1-1]=='0' && s[p2-1]=='0')
				{
					flag=1;
					s[p1-1] = '1';
					s[p2-1] = '1';
					break;
				}
				p1++;
				p2--;
			}
			if(!flag)
				return "impossible";
			s[temp] = '0';
		}
	}
	s[x-1] = '2';
	//cout << s << endl;
	return s;
}

int main()
{
	TEST{
		ull x,n;
		cin >> x >> n;
		string p;
		if(n==1)
			cout << "2" << endl;
		else if(n==2)
			cout << "impossible" << endl;
		else{
			p = generate(n,x);
			cout << p << endl;
		}
	}
	return 0;
}
