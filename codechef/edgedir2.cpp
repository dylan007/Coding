/*=======================
Author    : Shounak Dey
Filename  : edgedir2.cpp
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
		ll n,m;
		cin >> n >> m;
		vector<vector<ll>> adj(n,vector<ll>());
		vector<pair<ll,ll>> edges;
		map<pair<ll,ll>,ll> edgind;
		vector<ll> deg(n,0);
		REP(i,m){
			ll x,y;
			cin >> x >> y;
			x--;y--;
			adj[x].PB(y);
			adj[y].PB(x);
			deg[x]++;
			deg[y]++;
			edgind[{x,y}] = i;
		}
		if(m&1){
			cout << -1 << endl;
			continue;
		}
		auto cmp = [](pair<ll,ll> lhs,pair<ll,ll> rhs){
			int f1,f2;
			f1 = lhs.second & 1;
			f2 = rhs.second & 1;
			if(f1==f2){
				if(lhs.second == rhs.second)
					return lhs.first < rhs.first;
				return lhs.second > rhs.second;
			}
			else
				return f1 < f2;
		};
		set<pair<ll,ll>,decltype(cmp)> q(cmp);
		REP(i,n){
			if(deg[i]>1)
				q.insert({i,deg[i]});
		}
		vector<ll> visited(n,0);
		vector<ll> ans(m,-1);
		while(!q.empty()){
			auto curr = *(q.begin());
			q.erase(q.begin());
			if(deg[curr.first]==0){
				visited[curr.first]=1;
				continue;
			}
			// cout << curr.first+1 << " " << curr.second << endl;
			if(deg[curr.first]&1 && deg[curr.first]>1){
				REP(i,adj[curr.first].size()-1){
					ll ep = adj[curr.first][i];
					if(visited[ep])
						continue;
					ll dir = edgind.find({curr.first,ep})!=edgind.end();
					ll pos;
					if(dir)
						pos = edgind[{curr.first,ep}];
					else
						pos = edgind[{ep,curr.first}];
					if(ans[pos]>-1)
						continue;
					ans[pos] = dir;
					auto ele = q.find({ep,deg[ep]});
			 		if(ele != q.end())
			 			q.erase(ele);
			 		deg[ep]--;
			 		q.insert({ep,deg[ep]});
					deg[curr.first]--;
				}
			}
			else if(!(deg[curr.first]&1)){
				REP(i,adj[curr.first].size()){
					ll ep = adj[curr.first][i];
					if(visited[ep])
						continue;
					ll dir = edgind.find({curr.first,ep})!=edgind.end();
					ll pos;
					if(dir)
						pos = edgind[{curr.first,ep}];
					else
						pos = edgind[{ep,curr.first}];
					if(ans[pos] > -1)
						continue;
					ans[pos] = dir;
					auto ele = q.find({ep,deg[ep]});
			 		if(ele != q.end())
			 			q.erase(ele);
			 		deg[ep]--;
			 		q.insert({ep,deg[ep]});
					deg[curr.first]--;	
				}
				visited[curr.first] = 1;
			}
			// for(auto it: deg)
			// 	cout << it << " ";
			// cout << endl;
		}
		ll f=0;
		for(auto it: visited)
			f |= (it==0);
		for(auto it: ans)
			f |= (it==-1);
		if(f)
			cout << -1 << endl;
		else{
			for(auto it: ans)
				cout << it << " ";
			cout << endl;
		}
	}	
	return 0;
}