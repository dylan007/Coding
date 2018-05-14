/*=======================
Author    : Shounak Dey
Filename  : 978d.cpp
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

int main()
{
	ll n;
	cin >> n;
	vector<ll> arr(n);
	REP(i,n){
		cin >> arr[i];
	}
	if(n==1)
		cout << 0 << endl;
	else{
		ll m=LONG_MAX,flag=0;
		REP(fdiff,3){
			REP(sdiff,3){
				vector<ll> x;
				x.PB(arr[0]+fdiff-1);
				x.PB(arr[1]+sdiff-1);
				ll d = x[1]-x[0];
				// cout << x[0] << " " << x[1] << endl;
				ll f=0,ans=abs(fdiff-1)+abs(sdiff-1);
				FOR(i,2,n){
					ll currd = d*(i-1);
					ll term = currd + x[1];
					// error(currd,d,term);
					// cout << endl;
					if(abs(term - arr[i]) > 1){
						f = -1;
						break;
					}
					else
						ans += abs(term-arr[i]);
				}
				if(f==0){
					// error(x[0],x[1],ans);
					// cout << endl;
					flag = 1;
					m = min(ans,m);
				}
				// cout << "Next" << endl;
			}
		}
		if(flag)
			cout << m << endl;
		else
			cout << -1 << endl;
	}
	return 0;
}