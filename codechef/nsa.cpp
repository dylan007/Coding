/*=======================
Author    : Shounak Dey
Filename  : nsa.cpp
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

int main()
{
	TEST{
		string a;
		cin >> a;
		ll n = a.length();
		vector<vector<ll>> pre(n,vector<ll>(26,0));
		ll start,end;
		start=25;
		end = 0;
		REP(i,n){
			ll temp = a[i]-'a';
			pre[i][temp]++;
			start = min(start,temp);
			end = max(end,temp);
			FOR(j,1,26)
				pre[i][j] += pre[i][j-1];
			if(i>0){
				REP(j,26)
					pre[i][j] += pre[i-1][j];
			}
		}
		ll tot=0,out=LONG_MAX;
		REP(i,n){
			ll temp = a[i]-'a',l,r;
			l = r = 0;
			if(temp<25)
				r = pre[n-1][25]-pre[n-1][temp];
			if(temp<25 && i>0)
				l = pre[i][25]-pre[i][temp];
			tot += r-l;
			// error(a[i],temp);
		}
		// error(tot);
		out = tot;
		REP(i,n){
			ll p = ll(a[i]-'a');
			string b = a;
			ll ans = 0;
			ll temp = a[i]-'a',l,r;
			l = r = 0;
			if(temp<25)
				r = pre[n-1][25]-pre[n-1][temp];
			if(temp<25 && i>0)
				l = pre[i][25]-pre[i][temp];
			ans += r-l;
			l=r=0;
			if(temp>0 && i>0)
				r = pre[i-1][temp-1];
			ans += r;
			tot -= ans;
			// error(tot);
			// cout << endl;
			for(int j=start;j<=end;j++){
				b[i] = char('a'+j);
				ll rep = 0;
				ll temp = b[i]-'a',l,r;
				l = r = 0;
				if(temp<25)
					r = pre[n-1][25]-pre[n-1][temp];
				if(temp<25 && i>0)
					l = pre[i][25]-pre[i][temp];
				rep += r-l;
				l=r=0;
				if(temp>0 && i>0)
					r = pre[i-1][temp-1];
				rep += r;
				rep = tot + rep + max(p-j,j-p);
				error(a,b,rep);
				if(rep < out){
					out = rep;
				}
			}
			tot += ans;
			// error(tot);
			cout << endl;
		}
		cout << out << endl;
	}
	return 0;
} 