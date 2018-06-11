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
		ll n,d,sum=0;
		cin >> n >> d;
		vector<pair<ll,pair<ll,ll>>> q;
		REP(i,n){
			ll D,t,s;
			cin >> D >> t >>s;
			q.PB(MK(D-1,MK(t,s)));
			sum += t*s;
		}		
		sort(q.begin(),q.end(),[](const auto& lhs,const auto &rhs){
			return lhs.first < rhs.first;
		});
		// for(auto it:q)
		// 	cout << it.first << " " << it.second.first << " " << it.second.second << endl;
		priority_queue<ll> Q;
		ll curr=0,ans=0;
		map<ll,ll> count;
		REP(i,d){
			while(curr<n && i>=q[curr].first){
				ll temp = q[curr].second.second;
				if(count.find(temp) == count.end()){
					Q.push(q[curr].second.second);
					count[temp] = q[curr].second.first;
				}
				else
					count[temp] += q[curr].second.first;
				curr++;
			}
			if(!Q.empty()){
				ans += Q.top();
				count[Q.top()]--;
				if(count[Q.top()] == 0)
					Q.pop();
			}
			// error(i,ans);
		}
		cout << sum - ans << endl;
	}
	return 0;
}