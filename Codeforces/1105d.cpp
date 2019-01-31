/*=======================
Author    : Shounak Dey
Filename  : 1105d.cpp
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
	ll n,m,p;
	cin >> n >> m >> p;
	vector<ll> s(p+1);
	REP(i,p)
		cin >> s[i+1];
	vector<string> a(n);
	REP(i,n)
		cin >> a[i];
	vector<vector<ll>> disc(n,vector<ll>(m,-1));
	vector<vector<ll>> moves(n,vector<ll>(m,10000000000));
	vector<queue<pair<ll,ll>>> start(10,queue<pair<ll,ll>>());
	REP(i,n){
		REP(j,m){
			if(a[i][j]>='1' && a[i][j]<='9'){
				start[a[i][j]-'0'].push({i,j});
				moves[i][j] = 0;
				disc[i][j] = a[i][j]-'0';
			}
			if(a[i][j]=='#')
				moves[i][j] = -1;
		}
	}
	FOR(i,1,p+1){
		queue<pair<ll,ll>> q = start[i];
		while(!q.empty()){
			pair<ll,ll> curr = q.front();
			q.pop();
			ll l = moves[curr.F][curr.S]+1;
			l = (l + s[i]-1)/s[i];
			if(curr.F>0 && moves[curr.F-1][curr.S]>l){
				moves[curr.F-1][curr.S] = l;
				disc[curr.F-1][curr.S] = i;
				q.push({curr.F-1,curr.S});
			}
			if(curr.F<(n-1) && moves[curr.F+1][curr.S]>l){
				moves[curr.F+1][curr.S] = l;
				disc[curr.F+1][curr.S] = i;
				q.push({curr.F+1,curr.S});	
			}
			if(curr.S>0 && moves[curr.F][curr.S-1]>l){
				moves[curr.F][curr.S-1] = l;
				disc[curr.F][curr.S-1] = i;
				q.push({curr.F,curr.S-1});
			}
			if(curr.S<(m-1) && moves[curr.F][curr.S+1]>l){
				moves[curr.F][curr.S+1] = l;
				disc[curr.F][curr.S+1] = i;
				q.push({curr.F,curr.S+1});
			}
		}
		REP(j,n){
			REP(k,m){
				if(disc[j][k]==i){
					moves[j][k] = (moves[j][k]+s[i]-1)/s[i];
				}
			}
		}
	}
	vector<ll> count(10,0);
	REP(i,n){
		REP(j,m){
			if(disc[i][j]>=0)
				count[disc[i][j]]++;
		}
	}
	for(auto it: disc){
		for(auto its:it)
			cout << its << " ";
		cout << endl;
	}
	FOR(i,1,p+1)
		cout << count[i] << " ";
	cout << endl;
	return 0;
}