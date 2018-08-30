/*=======================
Author    : Shounak Dey
Filename  : t29.cpp
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
	ll n,q;
	cin >> n >> q;
	vector<ll> arr(n);
	REP(i,n){
		cin >> arr[i];
		arr[i] = lim-arr[i];
	}
	map< pair<pair<ll,ll>,ll>, vector<ll> > query;
	vector<pair<pair<ll,ll>,ll>> qu;
	REP(i,q){
		ll l,r,x;
		cin >> l >> r >> x;
		l--;r--;
		pair<pair<ll,ll>,ll> temp;
		temp = MK(MK(l,r),x);
		if(query.find(temp) != query.end())
			query[temp].PB(i);
		else{
			query[temp] = vector<ll>();
			query[temp].PB(i);
			qu.PB(MK(MK(l,r),x));
		}
	}
	sort(qu.begin(),qu.end(),[](const auto &lhs,const auto &rhs){
		if(lhs.first.first==rhs.first.first)
			return lhs.first.second<rhs.first.second;
		return lhs.first.first<rhs.first.first;
	});
	// for(auto it:qu)
	// 	cout << it.first.first << " " << it.first.second << " " << it.second << endl;
	set<ll> s;
	ll start,end;
	start = -1;
	end = -1;
	vector<ll> out(q,0);
	for(auto que:qu){
		ll l,r,x;
		l = que.first.first;
		r = que.first.second;
		x = que.second;
		if(start==-1 && end==-1){
			FOR(i,l,r+1)
				s.insert(arr[i]);
			start = l;
			end = r;
		}
		else{
			while(start<l)
				s.erase(arr[start++]);
			if(end>r){
				while(end>r)
					s.erase(arr[end--]);
			}
			else{
				while(end<=r)
					s.insert(arr[end++]);
				end--;
			}
		}
		set<ll>::iterator it = s.lower_bound(x);
		ll ans=0;
		if(it == s.end())
			ans = *(s.rbegin());
		else if(it == s.begin())
			ans = *(s.begin());
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
		REP(i,query[que].size()){
			// cout << query[que][i] << endl;
			out[query[que][i]] = lim-ans;
		}
	}
	for(auto it:out)
		cout << it << endl;
	return 0;
}