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

ll check(ll x,vector<ll> arr){
	if(x<0)
		return 0;
	arr.PB(x);
	sort(arr.rbegin(),arr.rend());
	ll n = arr.size();
	vector<ll> suff(n);
	ll pos = n-2;
	suff[n-1] = 0;
	while(pos>=0){
		suff[pos] = suff[pos+1] + min(arr[pos],pos+1);
		pos--;
	}
	ll tot=0;
	REP(i,n){
		tot += arr[i];
		if(tot > ((i*(i+1)) + suff[i]))
			return 0;
	}
	return 1;
}

int main()
{
	fast_io;
	ll n;
	cin >> n;
	vector<ll> arr(n);
	REP(i,n)
		cin >> arr[i];
	// cout << "Input done" << endl;
	ll par = 0;
	REP(i,n)
		par += arr[i]&1;
	par &= 1;
	//find min;
	ll l=0,r=250000-par;
	ll mid;
	while(l<=r){
		mid = (l+r)>>1;
		ll f1,f2;
		f1 = check(2*mid+par,arr);
		f2 = check(2*(mid-1)+par,arr);
		error(l,r,f1,f2,mid);
		if(f1 && !f2)
			break;
		if(f1 && f2)
			r = mid-1;
		else
			l = mid+1;
	}
	ll p1=mid;
	// find max;
	l=0;r=250000;
	while(l<=r){
		mid = (l+r)>>1;
		ll f1,f2;
		f1 = check(2*mid+par,arr);
		f2 = check(2*(mid+1)+par,arr);
		if(f1 && !f2)
			break;
		if(f1 && f2)
			l = mid-1;
		else
			r = mid+1;
	}
	ll p2=mid;
	error(p1,p2);
	if(p1>p2)
		cout << -1 << endl;
	else{
		while(p1<=p2){
			cout << p1 << " ";
			p1+=2;
		}
		cout << endl;
	}
	return 0;
}