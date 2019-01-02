/*=======================
Author    : Shounak Dey
Filename  : 1090d.cpp
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
	ll n,m;
	cin >> n >> m;
	vector<vector<ll>> adj(n,vector<ll>());
	REP(i,m){
		ll x,y;
		cin >> x >> y;
		x--;y--;
		adj[x].PB(y);
		adj[y].PB(x);
	}
	ll p1,p2;
	REP(i,n){
		p2=-1;
		vector<ll> v(n,0);
		for(auto it: adj[i])
			v[it]=1;
		FOR(j,i+1,n){
			if(v[j]==0){
				p2=j;
				break;
			}
		}
		if(p2!=-1){
			p1 = i;
			break;
		}
	}
	if(p2==-1)
		cout << "NO" << endl;
	else{
		cout << "YES" << endl;
		vector<ll> b(n,0);
		b[p1] = b[p2] = 1;
		ll curr = 3,pos=0;
		while(curr <= n){
			if(b[pos]>0){
				pos++;
				continue;
			}
			b[pos++] = curr++;
		}
		b[p2]++;
		REP(i,n)
			cout << b[i] << " ";
		cout << endl;
		b[p2]--;
		REP(i,n)
			cout << b[i] << " ";
		cout << endl;
	}
	return 0;
}