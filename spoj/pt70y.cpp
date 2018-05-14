/*=======================
Author    : Shounak Dey
Filename  : pt70y.cpp
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

int root(vector<int> parent,int x){
	while(x != parent[parent[x]])
		x = parent[parent[x]];
	return x;
}

int un(vector<int> &parent,vector<int> &size,int x,int y){
	int rx = root(parent,x);
	int ry = root(parent,y);
	if(rx == ry)
		return 1;
	if(size[rx] > size[ry]){
		parent[ry] = rx;
		size[rx] += size[ry];
		size[ry] = size[rx];
	}
	else{
		parent[rx] = ry;
		size[ry] += size[ry];
		size[rx] = size[ry];
	}
	return 0;
}

int main()
{
	int n,m;
	cin >> n >> m;
	if(n!= (m+1))
		cout << "NO" << endl;
	else{
		vector<int> parent(n),size(n);
		for(int i=0;i<n;i++){
			parent[i] = i;
			size[i] = i;
		}
		for(int i=0;i<m;i++){
			int x,y;
			cin >> x>> y;
			x--;y--;
			int f = un(parent,size,x,y);
			if(f){
				cout << "NO" << endl;
				return 0;
			}
		}
		cout << "YES" << endl;
	}
	return 0;
}
