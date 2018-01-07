/*=======================
Author    : Shounak Dey
Filename  : 911e.cpp
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
	int n,k;
	cin >> n >> k;
	vector<pair<int,int>> div;
	div.PB(MK(1,n));
	vector<int> prefix(k);
	REP(i,k)
		cin >> prefix[i];
	int i=0;
	while(1)
	{
		pair<int,int> p = div.back();
		int l,r;
		l = p.first;
		r = p.second;
		if(i==k)
			break;
		div.pop_back();
		if(prefix[i]<l || prefix[i]>r)
			return (cout << -1 << endl),0;
		if(l==r && l==prefix[i])
			l++;
		else if(l==prefix[i])
			div.PB(MK(l+1,r));
		else if(r==prefix[i])
			div.PB(MK(l,r-1));
		else
		{
			div.PB(MK(min(r,prefix[i]+1),r));
			div.PB(MK(l,max(l,prefix[i]-1)));
		}
		i++;
		// for(auto it:div)
		// 	cout << it.first << " " << it.second << endl;
		// cout << endl;
	}
	for(auto it:prefix)
		cout << it << " ";
	for(int j=div.size()-1;j>=0;j--)
	{
		int l,r;
		l = div[j].first;
		r = div[j].second;
		for(int i=r;i>=l;i--)
			cout << i << " ";
	}
	cout << endl;
	return 0;
}
