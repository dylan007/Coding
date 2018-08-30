/*=======================
Author    : Shounak Dey
Filename  : t292.cpp
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

#define lim 1000000000

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	ll n,q;
	cin >> n >> q;
	vector<ll> arr(n);
	REP(i,n)
		cin >> arr[i];
	ll block = ll(sqrt(n));
	ll nblocks = n/block + ((n%block)!=0);
	vector<set<ll>> blocks(nblocks,set<ll>());
	REP(i,n){
		blocks[i/block].insert(lim-arr[i]);
	}
	while(q--){
		ll l,r,x;
		cin >> l >> r >> x;
		l--;r--;
		ll m=-1;
		ll diff=INT_MAX;
		ll sb,eb;
		sb = l/block;
		eb = r/block;
		cout << sb << " " << eb << endl;
		if(sb == eb){
			set<ll> temp;
			for(ll i=l;i<=r;i++)
				temp.insert(lim-arr[i]);
			set<ll>::iterator it = temp.lower_bound(x);
			ll ans=0;
			if(it == temp.end())
				ans = *(temp.rbegin());
			else if(it == temp.begin())
				ans = *(temp.begin());
			else{
				ll a,b;
				it--;
				a = *(it);
				it++;
				b = *(it);
				// cout << a << " " << b << endl;
				if(abs(x-a)>abs(x-b))
					ans = b;
				else
					ans = a;
			}
			cout << lim-ans << endl;
		}
		else{
			FOR(i,sb+1,eb){
				set<ll>::iterator it = blocks[i].lower_bound(x);
				ll ans=0;
				if(it == blocks[i].end())
					ans = *(blocks[i].rbegin());
				else if(it == blocks[i].begin())
					ans = *(blocks[i].begin());
				else{
					ll a,b;
					it--;
					a = *(it);
					it++;
					b = *(it);
					// cout << a << " " << b << endl;
					if(abs(x-a)>abs(x-b))
						ans = b;
					else
						ans = a;
				}
				if(m==-1){
					m = ans;
					diff = abs(x-m);
				}
				else{
					if(abs(x-ans)<diff){
						diff = abs(x-ans);
						m = ans;
					}
					else if(abs(x-ans) == diff){
						m = max(m,ans);
					}
				}
			}


			set<ll> left,right;
			ll lend = (sb+1)*block;
			for(ll i=l;i<lend;i++)
				left.insert(lim-arr[i]);
			set<ll>::iterator it = left.lower_bound(x);
			ll ans=0;
			if(it == left.end())
				ans = *(left.rbegin());
			else if(it == left.begin())
				ans = *(left.begin());
			else{
				ll a,b;
				it--;
				a = *(it);
				it++;
				b = *(it);
				// cout << a << " " << b << endl;
				if(abs(x-a)>abs(x-b))
					ans = b;
				else
					ans = a;
			}
			if(m==-1){
				m = ans;
				diff = abs(x-m);
			}
			else{
				if(abs(x-ans)<diff){
					diff = abs(x-ans);
					m = ans;
				}
				else if(abs(x-ans) == diff){
					m = max(m,ans);
				}
			}


			ll rstart = (eb)*block;
			for(ll i=rstart;i<=r;i++)
				right.insert(lim-arr[i]);
			it = right.lower_bound(x);
			ans=0;
			if(it == right.end())
				ans = *(right.rbegin());
			else if(it == right.begin())
				ans = *(right.begin());
			else{
				ll a,b;
				it--;
				a = *(it);
				it++;
				b = *(it);
				// cout << a << " " << b << endl;
				if(abs(x-a)>abs(x-b))
					ans = b;
				else
					ans = a;
			}
			if(m==-1){
				m = ans;
				diff = abs(x-m);
			}
			else{
				if(abs(x-ans)<diff){
					diff = abs(x-ans);
					m = ans;
				}
				else if(abs(x-ans) == diff){
					m = max(m,ans);
				}
			}
			cout << lim-m << endl;
		}
	}
	return 0;
}