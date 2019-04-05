/*=======================
Author    : Shounak Dey
Filename  : a.cpp
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

void bfs(vector<vector<ll>> &dist,vector<string> &arr,ll x,ll y){
	ll n = dist.size();
	ll m = dist[0].size();
	auto check = [n,m](ll a,ll b){
		if(a<0 || a>=n)
			return 1;
		if(b<0 || b>=m)
			return 1;
		return 0;
	};
	queue<pair<pair<ll,ll>,ll>> q;
	vector<vector<ll>> vis(n,vector<ll>(m,0));
	// q.push(MK(MK(x,y),0));
	REP(i,n){
		REP(j,m)
			if(arr[i][j]=='1') q.push(MK(MK(i,j),0));
	}
	while(!q.empty()){
		pair<pair<ll,ll>,ll> curr = q.front();
		q.pop();
		if(check(curr.F.F,curr.F.S) || vis[curr.F.F][curr.F.S])
			continue;
		vis[curr.F.F][curr.F.S] = 1;
		// cout << curr.F.F << " " << curr.F.S << endl;
		dist[curr.F.F][curr.F.S] = min(dist[curr.F.F][curr.F.S],curr.S); 
		q.push(MK(MK(curr.F.F+1,curr.F.S),curr.S+1));
		q.push(MK(MK(curr.F.F-1,curr.F.S),curr.S+1));
		q.push(MK(MK(curr.F.F,curr.F.S+1),curr.S+1));
		q.push(MK(MK(curr.F.F,curr.F.S-1),curr.S+1));
	}
	return;
}

ll bfs2(vector<vector<ll>> dist,vector<string> &arr,ll x,ll y){
	ll n = dist.size();
	ll m = dist[0].size();
	auto check = [n,m](ll a,ll b){
		if(a<0 || a>=n)
			return 1;
		if(b<0 || b>=m)
			return 1;
		return 0;
	};
	ll ans=0;
	queue<pair<pair<ll,ll>,ll>> q;
	vector<vector<ll>> vis(n,vector<ll>(m,0));
	q.push(MK(MK(x,y),0));
	while(!q.empty()){
		pair<pair<ll,ll>,ll> curr = q.front();
		q.pop();
		if(check(curr.F.F,curr.F.S) || vis[curr.F.F][curr.F.S])
			continue;
		vis[curr.F.F][curr.F.S] = 1;
		ans = max(ans,min(curr.S,dist[curr.F.F][curr.F.S]));
		q.push(MK(MK(curr.F.F+1,curr.F.S),curr.S+1));
		q.push(MK(MK(curr.F.F-1,curr.F.S),curr.S+1));
		q.push(MK(MK(curr.F.F,curr.F.S+1),curr.S+1));
		q.push(MK(MK(curr.F.F,curr.F.S-1),curr.S+1));
	}
	return ans;
}

int main()
{
	fast_io;
	int T;
	cin >> T;
	REP(test,T){
		cout << "Case #" << test+1 << ": ";
		ll n,m;
		cin >> n >> m;
		vector<string> arr(n);
		REP(i,n)
			cin >> arr[i];
		vector<vector<ll>> dist(n,vector<ll>(m,LONG_MAX));
		// REP(i,n){
		// 	REP(j,m){
		// 		if(arr[i][j] == '1')
		// 			bfs(dist,arr,i,j);
		// 	}
		// }
		bfs(dist,arr,0,0);
		ll res = 0;
		vector<vector<ll>> dc(n,vector<ll>(m));
		REP(i,n){
			REP(j,m){
				res = max(dist[i][j],res);
				dc[i][j] = dist[i][j];
			}
		}
		ll out = LONG_MAX;
		REP(i,n){
			REP(j,m){
				arr[i][j] = '1';	
				out = min(out,bfs2(dist,arr,i,j));
				arr[i][j] = '0';
			}
		}
		cout << out << endl;
	}
	return 0;
}