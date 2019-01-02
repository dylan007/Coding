/*=======================
Author    : Shounak Dey
Filename  : digokeys.cpp
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
		vector<vector<ll>> adj(n,vector<ll>());
		REP(i,n-1){
			ll x;
			cin >> x;
			while(x--){
				ll p;
				cin >> p;
				adj[i].PB(p-1);
			}
			SORTV(adj[i]);
		}
		vector<ll> parent(n,-1);
		queue<ll> q;
		vector<ll> visited(n,0);
		q.push(0);
		visited[0]=1;
		while(!q.empty()){
			ll curr = q.front();
			q.pop();
			for(auto it: adj[curr]){
				if(!visited[it]){
					visited[it] = 1;
					q.push(it);
					parent[it] = curr;
				}
			}
		}
		if(visited[n-1]){
			vector<ll> ans;
			ll curr=parent[n-1];
			while(curr != -1){
				ans.PB(curr);
				curr = parent[curr];
			}
			cout << ans.size() << endl;
			for(auto it=ans.rbegin();it!=ans.rend();it++)
				cout << (*it)+1 << " ";
			cout << endl;
		}
		else
			cout << -1 << endl;
		cout << endl;
	}
	return 0;
}