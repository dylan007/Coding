/*=======================
Author    : Shounak Dey
Filename  : 580c.cpp
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
#define dispv(a) for(auto it:a) cout << it << " ";cout << endl;

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

void dfs(vector<int> state,vector<vector<int>> child,vector<vector<int>> parent,vector<int> &c,int loss,int curr)
{

	// cout << "Display" << endl;
	// for(int i=0;i<state.size();i++)
	// 	cout << child[i].size() << endl;
	// cout << curr << " size " << child[curr].size() << endl;
	if(child[curr].size()==0){
		c[curr] = loss+state[curr];
		return;
	}
	c[curr] = -1;
	if(state[curr])
		loss += state[curr];
	else
		loss = 0;
	//dispv(child[curr]);
	for(int i=0;i<child[curr].size();i++)
		dfs(state,child,parent,c,loss,child[curr][i]);
	return;
}


int main()
{
	int n,k;
	cin >> n >> k;
	int m = n-1;
	vector<int> state(n);
	for(int i=0;i<n;i++)
		cin >> state[i];
	vector<vector<int>> parent,child;
	vector<int> temp;
	for(int i=0;i<n;i++){
		parent.PB(temp);
		child.PB(temp);
	}
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin >> x >> y;
		x--;
		y--;
		parent[max(x,y)].PB(min(x,y));
		child[min(x,y)].PB(max(x,y));
	}
	vector<int> c(n);
	dfs(state,child,parent,c,0,0);
	int ans=0;
	dispv(c);
	for(auto it:c) ans+=(it<=k && it>=0);
	cout << ans << endl;
	return 0;
}
