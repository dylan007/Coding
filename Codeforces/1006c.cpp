/*=======================
Author    : Shounak Dey
Filename  : 1006c.cpp
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

ll binsearch(vector<ll> right,ll start,ll end,ll x){
	while(start<=end){
		ll mid = (start+end)/2;
		if(right[mid]==x)
			return x;
		if(right[mid]<x)
			end = mid-1;
		else
			start = mid+1;
	}
	return -1;
}

int main()
{
	ll n;
	cin >> n;
	vector<ll> arr(n),left(n),right(n);
	REP(i,n)
		cin >> arr[i];
	left[0] = arr[0];
	right[n-1] = arr[n-1];
	FOR(i,1,n)
		left[i] = left[i-1]+arr[i];
	for(int i=(n-2);i>=0;i--)
		right[i] = right[i+1]+arr[i];
	// for(auto it:left)
	// 	cout << it << " ";
	// cout << endl;
	// for(auto it:right)
	// 	cout << it << ' ';
	// cout << endl; 
	ll ans=0;
	REP(i,n-1){
		// error(left[i]);
		// cout << binsearch(right,i+1,n-1,left[i]) << endl;
		ans = max(ans,binsearch(right,i+1,n-1,left[i]));
	}
	cout << ans << endl;
	return 0;
}