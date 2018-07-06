/*=======================
Author    : Shounak Dey
Filename  : dishown.cpp
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

ll find(vector<ll> &parent,ll x){
	if(x != parent[x])
		parent[x] = find(parent,parent[x]);
	return parent[x];
}

int main()
{
	// ios_base::sync_with_stdio(false);
	TEST{
		ll n;
		readl(n);
		vector<ll> size(n);
		REP(i,n)
			readl(size[i]);
		vector<ll> parent(n);
		REP(i,n)
			parent[i] = i;
		ll q;
		readl(q);
		while(q--){
			ll c;
			readl(c);
			if(c==0){
				ll x,y;
				readl(x);readl(y);
				x--;y--;
				ll rootx = find(parent,x);
				ll rooty = find(parent,y);
				if(rootx == rooty)
					cout << "Invalid query!" << endl;
				if(size[rootx] > size[rooty]){
					parent[rooty] = rootx;
					// size[rootx] += size[rootx]; 
				}
				else if(size[rooty] > size[rootx]){
					parent[rootx] = rooty;
					// size[rooty] += size[rootx];
				}
			}
			else{
				ll x;
				readl(x);
				x--;
				ll root = find(parent,x);
				cout << root+1 << endl;
			}
		}
	}
	return 0;
}