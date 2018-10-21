/*=======================
Author    : Shounak Dey
Filename  : 437c.cpp
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
	int n,m;
	cin >> n >> m;
	vector<int> v(n,0);
	REP(i,n)
		cin >> v[i];
	vector<vector<int>> adj(n,vector<int>());
	vector<int> discarded(n,0);
	vector<int> weights(n,0);
	REP(i,m){
		int x,y;
		cin >> x >> y;
		x--;y--;
		adj[x].PB(y);
		adj[y].PB(x);
		weights[x] += v[y];
		weights[y] += v[x];
	}
	for(auto it:weights)
		cout << it << " ";
	cout << endl;
	int ans=0;
	REP(i,n){
		int m,index;
		m = INT_MAX;
		index = -1;
		REP(j,n){
			if(m > weights[j]){
				m = weights[j];
				index = j;
			}
		}
		error(m,index);
		ans += weights[index];
		weights[index] = INT_MAX;
		REP(j,adj[index].size())
			weights[j] -= v[index];
		for(auto it:weights)
			cout << it << " ";
		cout << endl;
	}
	cout << endl;
	cout << ans << endl;
	return 0;
}