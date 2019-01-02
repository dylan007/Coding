/*=======================
Author    : Shounak Dey
Filename  : 1093b.cpp
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
#define popc(a) __builtin_popcount(a) // count set bits
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

int main()
{
	fast_io;
	TEST{
		string a;
		cin >> a;
		vector<ll> c(26,0);
		REP(i,a.length())
			c[a[i]-'a']++;
		int f=0;
		REP(i,26){
			if(c[i]==a.length()){
				f=1;
				break;
			}
		}
		if(f)
			cout << -1 << endl;
		else{
			map<char,ll> c;
			REP(i,a.length()){
				if(c.find(a[i])==c.end())
					c[a[i]]=1;
				else
					c[a[i]]++;
			}
			map<char,ll>::iterator it = c.begin();
			char a,b;
			a = it->first;
			it->second--;
			it++;
			it->second--;
			b = (it)->first;
			cout << a;
			it--;
			while(it!=c.end()){
				ll tmp = it->second;
				while(tmp--)
					cout << it->first;
				it++;
			}
			cout << b << endl;
		}
	}
	return 0;
}