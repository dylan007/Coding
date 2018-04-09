/*=======================
Author    : Shounak Dey
Filename  : buglife.cpp
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

struct comp{
	bool operator()(pair<int,int> const &a,pair<int,int> const &b){
		return (a.second<b.second || ((a.second == b.second) && (a.first>b.second)));
	}
};

int main()
{
	TEST{
		int n,m;
		cin >> n >> m;
		vector<int> temp;
		vector<vector<int>> adj(n,temp);
		vector<pair<int,int>> degree;
		REP(i,n)
			degree.PB(MK(i,0));
		REP(i,m){
			int x,y;
			cin >> x >> y;
			adj[x-1].PB(y-1);
			adj[y-1].PB(x-1);
			degree[x-1].second++;
			degree[y-1].second++;
		}
		make_heap(degree.begin(),degree.end(),comp());
		vector<int> order;
		for(auto it:degree){
			order.PB(it.first);
		}
		vector<int> color(n,0);
		int shade=1;
		while(check(color)){
			
		}
	}
	return 0;
}
