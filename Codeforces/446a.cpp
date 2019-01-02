/*=======================
Author    : Shounak Dey
Filename  : 446a.cpp
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

int main()
{
	fast_io;
	ll n;
	cin >> n;
	vector<ll> arr(n);
	REP(i,n)
		cin >> arr[i];
	vector<ll> L(n),R(n);
	L[0] = R[n-1] = 0;
	if(n>=2)
		R[n-2] = 1;
	ll curr=1;
	L[1] = 1;
	FOR(i,1,n-1){
		if(arr[i]>arr[i-1])
			curr++;
		else
			curr=1;
		L[i+1] = curr;
	}
	curr = 1;
	for(ll i=(n-2);i>0;i--){
		if(arr[i]<arr[i+1])
			curr++;
		else
			curr = 1;
		R[i-1] = curr;
	}
	ll ans=0;
	REP(i,n){
		if(i==0)
			ans = max(ans,R[i]+1);
		else if(i==(n-1))
			ans = max(ans,L[i]+1);
		else if(arr[i+1]>(arr[i-1]+1ll))
			ans = max(ans,L[i]+R[i]+1);
		else
			ans = max(ans,max(L[i]+1,R[i]+1));
	}
	// for(auto it: L)
	// 	cout << it << " ";
	// cout << endl;
	// for(auto it: R)
	// 	cout << it << " ";
	// cout << endl;
	cout << ans << endl;
	return 0;
}