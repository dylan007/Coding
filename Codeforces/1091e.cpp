/*=======================
Author    : Shounak Dey
Filename  : 1091e.cpp
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

#define MAXN 100000

ll check(ll x,vector<ll> deg){
	deg.PB(x);
	sort(deg.rbegin(),deg.rend());
	vector<ll> pre(deg.size());
	ll n = deg.size();
	for(ll i=(n-1);i>=0;i--)
		pre[i] = min(i+1,deg[i]);
	REP(i,n-1){
		ll p = i*(i+1) + pre[i+1];
		if(p<deg[i])
			return 0;
	}
	if(deg[n-1] > (n*(n-1)))
		return 0;
	return 1;
}

int main()
{
	fast_io;
	ll n;
	cin >> n;
	vector<ll> deg(n);
	REP(i,n)
		cin >> deg[i];
	ll start = 1,end = MAXN;
	ll mid;
	while(start <= end){
		mid = (start + end)>>1;
		if(mid == 1)
			break;
		ll f1 = check(mid-1,deg);
		ll f2 = check(mid,deg);
		if(!f1 && f2)
			break;
		if(f1 && f2)
			end = mid;
		else 
			start = mid;
		error(start,end);
	} 	
	if(start > end){
		cout << -1 << endl;
		return 0;
	}
	ll p1 = mid;
	start = 1;
	end = MAXN;
	while(start <= end){
		mid = (start + end)>>1;
		if(mid == MAXN)
			break;
		ll f1 = check(mid+1,deg);
		ll f2 = check(mid,deg);
		if(!f1 && f2)
			break;
		if(f1 && f2)
			end = mid+1;
		else
			start = mid-1;
	}
	if(start>end){
		cout << -1 << endl;
		return 0;
	}
	while(p1 <= mid){
		cout << p1 << " ";
		p1 += 2;
	}
	cout << endl;
	return 0;
}