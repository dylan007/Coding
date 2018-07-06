/*=======================
Author    : Shounak Dey
Filename  : 992b.cpp
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

ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}

ll lcm(ll a, ll b){
	return (a*b)/gcd(a,b);
}

int main()
{
	ll l,r,x,y;
	cin >> l >> r >> x >> y;
	ll prod;
	int ans=0;
	if(y%x){
		cout << 0 << endl;
		return 0;
	}
	prod = y/x;
	if(l==r){
		if(x!=y)
			cout << 0 << endl;
		else if(x==y){
			if(x!=l)
				cout << 0 << endl;
			else
				cout << 1 << endl;
		}
		return 0;
	}
	for(ll i=l;i*i<=prod;i++){
		if((prod%i)==0){
			ll a,b;
			a = i;
			b = prod/i;
			// cout << a << " " << b << endl;
			if(a>r)
				break;
			if(b>r)
				continue;
			if(gcd(a,b)==x && lcm(a,b)==prod){
				// cout << a << " " << b << endl;
				ans += 2 - (a==b);
			}
		}
	}
	cout << ans << endl;
	
	return 0;
}