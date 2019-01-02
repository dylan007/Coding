/*=======================
Author    : Shounak Dey
Filename  : 1092c.cpp
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
	n--;
	n <<= 1;
	vector<pair<string,ll>> arr(n);
	REP(i,n){
		cin >> arr[i].first;
		arr[i].second = i;
	}
	sort(arr.begin(),arr.end(),[](pair<string,ll> a,pair<string,ll> b){
		return a.first.length()<b.first.length();
	});
	string a,b;
	a = arr[n-2].first;
	b = arr[n-1].first;
	ll f=0;
	FOR(i,1,a.length()){
		if(a[i]!=b[i])
			f=1;
	}
	vector<ll> ps(n);
	string pre,suf;
	if(f){
		ps[arr[n-1].second] = 0;
		ps[arr[n-2].second] = 1;
		pre = b;
		suf = a;
	}
	else{
		ps[arr[n-1].second] = 1;
		ps[arr[n-2].second] = 0;
		pre = a;
		suf = b;
	}
 	auto mpre = [](string a,string b){
		REP(i,a.length()){
			if(a[i]!=b[i])
				return 0;
		}
		return 1;
	};
	ll c = (n/2) - 1;
	cout << pre << " " << suf << endl;
	REP(i,n-2){
		error(i,c,arr[i].first);
		if(mpre(arr[i].first,pre) && c>0){
			c--;
			ps[arr[i].second] = 0;
		}
		else
			ps[arr[i].second] = 1;
	}
	REP(i,n)
		cout << (ps[i]?"S":"P");
	cout << endl;
	return 0;
}