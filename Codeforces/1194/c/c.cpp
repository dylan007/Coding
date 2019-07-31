/*=======================
Author    : Shounak Dey
=======================	*/

#include<bits/stdc++.h>

using namespace std;

using ll = long long int;
using ull = unsigned long long int;

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
		string s,t,p;
		cin >> s >> t >> p;
		ll ls,lt,lp;
		ls = s.length();
		lt = t.length();
		lp = p.length();
		if(ls>lt){
			cout << "NO" << endl;
			continue;
		}
		else if(ls==lt){
			if(s==t)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
			continue;
		}
		ll dp[ls+1][lt+1];
		REP(i,ls+1){
			REP(j,lt+1){
				if((i==0)||(j==0))
					dp[i][j]=0;
				else if(s[i-1]==t[j-1])
					dp[i][j] = dp[i-1][j-1]+1;
				else
					dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
			}
		}
		if(dp[ls][lt]!=ls)
			cout << "NO" << endl;
		else{
			vector<ll> c(26,0);
			REP(i,lt)
				c[t[i]-'a']++;
			REP(i,ls)
				c[s[i]-'a']--;
			REP(i,lp){
				if(c[p[i]-'a']>0)
					c[p[i]-'a']--;
			}
			ll f=0;
			REP(i,26)
				f |= (c[i]!=0);
			if(f)
				cout << "NO" << endl;
			else
				cout << "YES" << endl;
		}
	}
	return 0;
}

