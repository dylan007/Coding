/*=======================
Author    : Shounak Dey
Filename  : 978c.cpp
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

int binsearch(vector<int> arr,int x,int low,int high){
	int mid = (low+high)/2;
	if(mid == 0){
		if(arr[mid]>=x)
			return mid;
		else
			return binsearch(arr,x,mid+1,high);
	}
	else if(mid == (arr.size()-1)){
		if(arr[mid]<=x)
			return mid;
		else
			return binsearch(arr,x,low,mid-1);
	}
	else if(arr[mid]>=x && arr[mid-1]<x)
		return mid;
	else if(arr[mid]>x){
		return binsearch(arr,x,low,mid-1);
	}
	else{
		return binsearch(arr,x,mid+1,high);
	}
	return mid;
}

int main()
{
	ll n,m;
	cin >> n >> m;
	vector<ll> arr(n);
	vector<ll> pre(n);
	REP(i,n){
		cin >> arr[i];
		if(i==0)
			pre[i]=arr[i];
		else
			pre[i]=arr[i] + pre[i-1];
	}
	while(m--){
		ll x;
		cin >> x;
		ll index = lower_bound(pre.begin(),pre.end(),x)-pre.begin();
		cout << index+1 << " ";
		if(index == 0)
			cout << x << endl;
		else
			cout << x - pre[index-1] << endl;
	}
	return 0;
}