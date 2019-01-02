/*=======================
Author    : Shounak Dey
Filename  : agegal.cpp
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
	TEST{
		ll n;
		cin >> n;
		vector<ll> arr(n);
		REP(i,n)
			cin >> arr[i];
		ll d1,d2,m1,m2,y1,y2;
		cin >> y1 >> m1 >> d1;
		cin >> y2 >> m2 >> d2;
		if(y1<y2){
			ll ans=0;
			m1--;
			m2--;
			ans += (arr[m1]-d1+1);
			FOR(i,m1+1,n)
				ans += arr[i];
			ans += (y1%4)==0;
			// cout << "BY" << endl;
			// error(ans);
			ll tot=0;
			REP(i,n)
				tot += arr[i];
			FOR(y,y1+1,y2)
				ans += (tot + ((y%4)==0));
			// cout << "INT" << endl;
			// error(ans);
			REP(i,m2)
				ans += arr[i];
			ans += d2;
			cout << ans << endl;
		}
		else{
			ll ans=0;
			m1--;
			m2--;
			if(m2>m1){
				ans += (arr[m1]-d1+1);
				FOR(i,m1+1,m2)
					ans += arr[i];
				ans += d2;
			}
			else
				ans = d2-d1+1;
			cout << ans << endl;
		}
	}
	return 0;
}