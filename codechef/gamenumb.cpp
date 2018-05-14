/*=======================
Author    : Shounak Dey
Filename  : gamenumb.cpp
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
	TEST{
		ll n,k;
		cin >> n >> k;
		map<ll,ll> c;
		vector<ll> arr(n);
		ll sum=0,tot=0;
		REP(i,n){
			ll x;
			cin >> x;
			c[x] = 0;
			arr[i] = x;
		}
		REP(i,n){
			ll x;
			cin >> x;
			c[arr[i]]+=x;
			sum += arr[i]*x;
			tot += x;
		}
		map<ll,ll>::iterator it;
		vector<pair<ll,ll>> count;
		vector<ll> b(k);
		ll bs=0;
		REP(i,k){
			cin >> b[i];
			bs += b[i];
		}
		it = c.begin();
		while(it != c.end()){
			count.PB(MK(it->first,it->second));
			it++;
		}	
		ll l=0,r=count.size()-1;
		ll i=0;
		while(bs>0 && tot>0 && i<k){
			//cout << b[i] << endl;
			if(i%2 == 0){
				b[i] = tot-b[i];
				ll t = b[i];
				// error(t);
				while(b[i]>0 && l<n){
					if(b[i]>count[l].second){
						b[i] -= count[l].second;
						bs -= count[l].second;
						tot -= count[l].second;
						sum -= count[l].second * count[l].first;
						count[l].second = 0;
						l++;
					}
					else{
						bs -= b[i];
						tot -= b[i];
						sum -= b[i] * count[l].first;
						count[l].second -= b[i];
						b[i] = 0;
						if(count[l].second == 0)
							l++;
						break; 
					}
					// cout << "l"  << l << endl;
				}
				// error(tot);
			}
			else{
				b[i] = tot-b[i];
				ll t = b[i];
				while(b[i]>0 && r>0){
					if(b[i]>count[r].second){
						b[i] -= count[r].second;
						bs -= count[r].second;
						tot -= count[r].second;
						sum -= count[r].second * count[r].first;
						count[r].second = 0;
						r--;
					}
					else{
						bs -= b[i];
						tot -= b[i];
						sum -= b[i] * count[r].first;
						count[r].second -= b[i];
						b[i] = 0; 
						break;
					}
					// cout << "r" << r << endl;
				}
			}
			i++;
			// error(l,r);
			// cout << i << endl;
		}
		cout << sum << endl;
	}
	return 0;
}
