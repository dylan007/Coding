/*=======================
Author    : Shounak Dey
Filename  : binstring.cpp
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

string change(string a){
	string b;
	REP(i,a.length()){
		if(a[i]=='0')
			b += "1";
		else
			b += "0";
	}
	return b;
}

#define MAXN (ll)1e19

int main()
{
	fast_io;
	// string a = "0";
	// ll n;
	// cin >> n;
	// REP(i,n){
	// 	string b = a;
	// 	reverse(b.begin(),b.end());
	// 	a = a + "0" + change(b);
	// }
	// REP(i,a.length()){
	// 	if(((i+1)%4)==0)
	// 		cout << endl << a[i] << endl;
	// 	else
	// 	 	cout << a[i];
	// }
	// cout << endl;
	TEST{
		ll n;
		cin >> n;
		string a="001",b="011";
		if((n%4)!=0){
			if((n/4)&1)
				cout << b[(n%4)-1] << endl;
			else
				cout << a[(n%4)-1] << endl;
		}
		else{
			ll r = MAXN/4;
			ll l = 1;
			ll x = n/4;
			ll mid,curr=0;
			while(l<=r){
				mid = (l+r)>>1;
				if(mid==x)
					break;
				if(x < mid){
					curr = 0;
					r = mid-1;
				}
				else{
					curr = 1;
					l = mid+1;
				}
			}
			cout << curr << endl;
		}
	}
	return 0;
}