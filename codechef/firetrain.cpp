/*=======================
Author    : Shounak Dey
Filename  : firetrain.cpp
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

#define MOD 1000000007

int find(vector<int> parent,int x){
	while(x != parent[x]){
		parent[x] = parent[parent[x]];
		x = parent[x];
	}
	return parent[x];
}

void un(vector<int> &parent,vector<int> &size,int x,int y){
	int rootx = find(parent,x);
	int rooty = find(parent,y);
	if(rootx == rooty)
		return;
	if(size[rootx]>size[rooty]){
		parent[rooty] = rooty;
		size[rooty] += size[rootx];
	}
	else{
		parent[rooty] = rootx;
		size[rootx] += size[rooty];
	}
	return;
}

int main()
{
	TEST{
		int n,m;
		cin >> n >> m;
		vector<int> parent(n),size(n,1);
		REP(i,n)
			parent[i] = i;
		while(m--){
			int x,y;
			cin >> x >> y;
			x--;y--;
			un(parent,size,x,y);
		}
		map<int,int> c;
		ll ans=0,prod=1;
		for(auto it: parent)
			cout << it << " ";
		cout << endl;
		for(auto it: size)
			cout << it << " ";
		cout << endl;
		REP(i,n){
			if(c.find(parent[i]) == c.end()){
				ans++;
				prod = (prod * size[i])%MOD;
				c[parent[i]] = size[i];
			}
		}
		cout << ans << " " << prod << endl;
	}
	return 0;
}