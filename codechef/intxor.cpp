/*=======================
Author    : Shounak Dey
Filename  : intxor.cpp
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
	ll T;
	cin >> T;
	while(T--){
		ll n;
		cin >> n;
		vector<ll> arr(n+1);
		ll s1,s2,m1,m2;
		cout << 1 << " " << n << " " << n-1 << " " << 1 << endl;
		fflush(stdout);
		cin >> s1;
		if(s1==-1)
			return 0;
		cout << 1 << " " << n << " " << n-1 << " " << 2 << endl;
		fflush(stdout);
		cin >> s2;
		if(s2==-1)
			return 0;
		cout << "1 1 2 3" << endl;
		fflush(stdout);
		cin >> m1;
		if(m1 == -1)
			return 0;
		cout << "1 1 2 4" << endl;
		fflush(stdout);
		cin >> m2;
		if(m2 == -1)
			return 0;
		arr[3] = s1 ^ s2 ^ m1;
		arr[4] = s1 ^ s2 ^ m2;

		FOR(i,3,n-2){
			cout << 1 << " " << i << " " << i+1 << " " << i+2 << endl;
			fflush(stdout);
			ll curr;
			cin >> curr;
			if(curr==-1)
				return 0;
			arr[i+2] = curr ^ arr[i+1] ^ arr[i];
		}
		cout << 1 << " " << n-2 << " " << 3 << " " << n << endl;
		fflush(stdout);
		ll tmp;
		cin >> tmp;
		arr[n] = tmp ^ arr[n-2] ^ arr[3];
		arr[1] = s1 ^ arr[n] ^ arr[n-1];
		arr[2] = s2 ^ arr[n] ^ arr[n-1];
		cout << 2 << " ";
		FOR(i,1,n+1)
			cout << arr[i] << " ";
		cout << endl;
		fflush(stdout);
		cin >> n;
		if(n == -1)
			return 0;
	}
	return 0;
}