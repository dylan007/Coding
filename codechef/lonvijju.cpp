/*=======================
Author    : Shounak Dey
Filename  : lonvijju.cpp
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

void trav(int start,vector<vector<int>> next,vector<int> w,vector<int> &ans,int level,int curr){
	ans[level-1] = max(ans[level-1],curr+w[start]);
	curr += w[start];
	error(curr,level);
	REP(i,next[start].size())
		trav(next[start][i],next,w,ans,level+1,curr);
	return;
}

int main()
{
	TEST{
		int n;
		cin >> n;
		vector<int> w(n);
		REP(i,n)
			cin >> w[i];
		vector<int> p(n);
		REP(i,n-1)
			cin >> p[i];
		vector<vector<int>> next(n,vector<int>());
		REP(i,n-1)
			next[p[i]-1].PB(i+1);
		vector<int> ans(n,0);
		trav(0,next,w,ans,1,0);
		for(auto it:ans)
			cout << it << " ";
		cout << endl;
	}
	return 0;
}