/*=======================
Author    : Shounak Dey
Filename  : ipctrain.cpp
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
	 	ll n,d;
	 	cin >> n >> d;
	 	vector<pair<ll,pair<ll,ll>>> queries;
	 	ll sum=0;
	 	REP(i,n){
	 		ll p,t,s;
	 		cin >> p >> t >> s;
	 		queries.PB(MK(p,MK(s,t)));
	 		sum += t*s;
	 	}
	 	sort(queries.begin(),queries.end(),[](const auto &lhs, const auto &rhs){
	 		if(lhs.first != rhs.first)
	 			return lhs.first < rhs.first;
 			if(lhs.second.first != rhs.second.first)
 				return lhs.second.first > rhs.second.first;
 			return lhs.second.second > rhs.second.second;
	 	});
	 	// for(auto it:queries){
	 	// 	cout << it.first << " " << it.second.first << " " << it.second.second << endl;
	 	// }
	 	priority_queue<ll> q;
	 	ll curr=1;
	 	ll pos=0;
	 	map<ll,ll> count;
	 	ll ans=0;
	 	while(curr<=d){
	 		while(pos<n && curr>=queries[pos].first){
	 			if(count.find(queries[pos].second.first) != count.end()){
	 				if(count[queries[pos].second.first] == 0)
	 					q.push(queries[pos].second.first);
	 				count[queries[pos].second.first] += queries[pos].second.second;
	 			}
	 			else{
	 				q.push(queries[pos].second.first);
	 				count[queries[pos].second.first] = queries[pos].second.second;
	 			}
	 			pos++;
	 			if(pos == n)
	 				break;
	 		}
	 		if(q.empty()){
	 			curr++;
	 			continue;
	 		}
	 		ans += q.top();
	 		// error(q.top(),curr,pos);
	 		count[q.top()]--;
	 		if(count[q.top()] == 0)
	 			q.pop();
	 		curr++;
	 	}
	 	// cout << sum << " " << ans << endl;
	 	cout << sum - ans << endl;
	}
	return 0;
}