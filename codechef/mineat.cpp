/*=======================
Author    : Doraemon
Filename  : mineat.cpp
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

ll calc(vector<ll>arr,ll k){
	ll ans=0;
	//cout << k << endl;
	for(auto it:arr)
		ans += (it/k) + (it%k != 0);
	return ans;
}

ll binsearch(vector<ll> arr,ll low,ll high,ll h){
	ll mid = (low + high)/2;
	ll x = calc(arr,mid);
	ll z = calc(arr,mid+1);
	if(mid==1 && z>h)
		return mid;
	else if(mid==1 && z<=h)
		return binsearch(arr,low+1,mid,h);
	ll y = calc(arr,mid-1);
	if(x<=h && y>h)
		return mid;
	if(x>h)
		return binsearch(arr,mid+1,high,h);
	return binsearch(arr,low,mid-1,h);
}

int main()
{
	TEST{
		ll n,h;
		cin >> n >> h;
		vector<ll> arr(n);
		REP(i,n)
			cin >> arr[i];
		SORTV(arr);
		ll ans = binsearch(arr,1,1000000001,h);
		cout << ans << endl;
	}
	return 0;
}
