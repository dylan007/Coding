/*=======================
Author    : Shounak Dey
Filename  : 1095d.cpp
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
	vector<pair<ll,ll>> arr(n);
	REP(i,n){
		cin >> arr[i].F >> arr[i].S;
		arr[i].F --;
		arr[i].S --;
		if(arr[i].F > arr[i].S){
			ll tmp = arr[i].F;
			arr[i].F = arr[i].S;
			arr[i].S = tmp;
		}
	}
	vector<ll> ans(n);
	ans[0] = 0;
	ll next=-1;
	FOR(i,1,n){
		if(arr[i].F==0){
			if(arr[i].S==arr[0].F || (arr[i].S == arr[0].S))
				next = arr[i].S;
		}
	}
	ans[1] = next;
	ll pos=0,ind=0;
	while((pos+2)<n){
		// error(arr[pos].F,arr[pos].S,ans[pos+1]);
		if(arr[ind].F==ans[pos+1])
			ans[pos+2] = arr[ind].S;
		else
			ans[pos+2] = arr[ind].F;
		pos++;
		ind = ans[pos];
	}
	for(auto it: ans)
		cout << it+1 << " ";
	cout << endl;
	return 0;
}