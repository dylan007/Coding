/*=======================
Author    : Shounak Dey
=======================	*/

#include<bits/stdc++.h>

using namespace std;

using ll = long long int;
using ull = unsigned long long int;

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
#define all(v) v.begin(),v.end()


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
vector<vector<ll>> adj;
vector<pair<ll,ll>> edges;
vector<ll> path;
vector<ll> v;
ll p[3];

ll ord(ll a,ll b,ll x,ll y){
	ll s1 = (a<b);
	ll s2 = (x<y);
	return s1==s2;
}

ll bfs(ll start,ll end){
	queue<ll> q;
	ll n = adj.size();
	vector<ll> parent(n,-1);
	q.push(start);
	vector<ll> visited(n,0);
	while(!q.empty()){
		ll curr = q.front();
		q.pop();
		visited[curr]=1;
		for(auto it:adj[curr]){
			if(visited[it])
				continue;
			parent[it] = curr;
			q.push(it);
		}
	}
	ll ls = (p[0]<p[1]);
	ll rs = (p[1]<p[2]);
	ll curr = end;
	ll ret=0;
	while(parent[curr]!=-1){
		if(curr==end){
			curr = parent[curr];
			continue;
		}
		if(curr==start)
			break;
		ll cl = (start<curr);
		ll cr = (curr<end);
		if((ls==cl) && (rs==cr))
			ret++;
		curr = parent[curr];
	}
	return ret;
}

void dfs(ll start){
	v[start] = 1;
	path.PB(start);
	for(auto it:adj[start]){
		if(!v[it]){
			dfs(it);
		}
	}
	return;
}

vector<vector<ll>> st;

void build(ll curr, ll l, ll r){
	if(l==r){
		st[curr].PB(path[l]);
		return;
	}
	ll mid = (l+r)>>1;
	ll left,right;
	left = curr << 1;
	right = left | 1;
	build(left,l,mid);
	build(right,mid+1,r);
	merge(all(st[left]),all(st[right]),back_inserter(st[curr]));
};

ll query(ll curr, ll l, ll r, ll i, ll j, ll k){
	if((i>r) || (l>j))
		return 0;
	if((i<=l) && (r<=j))
		return lower_bound(all(st[curr]),k) - st[curr].begin();
	ll mid = (l+r)>>1;
	ll left = curr << 1;
	ll right = left | 1;
	return query(left,l,mid,i,j,k)+query(right,mid+1,r,i,j,k);
}

int main()
{
	fast_io;
	TEST{
		ll n;
		cin >> n;
		adj = vector<vector<ll>>(n,vector<ll>());
		edges = vector<pair<ll,ll>>();
		REP(i,3)
			cin >> p[i];
		vector<ll> deg(n,0);
		REP(i,n-1){
			ll x,y;
			cin >> x >> y;
			x--;y--;
			adj[x].PB(y);
			adj[y].PB(x);
			edges.PB(MK(x,y));
			deg[x]++;
			deg[y]++;
		}
		ll ans=0;
		if(n<=100){
			REP(i,n){
				if(p[0]<p[2]){
					FOR(j,i+1,n)
						ans += bfs(i,j);
				}
				else{
					REP(j,i)
						ans += bfs(i,j);
				}
			}
			cout << ans << endl;
			continue;
		}
		map<ll,ll> c;
		REP(i,n)
			c[deg[i]]++;
		set<ll> dd;
		REP(i,n)
			dd.insert(deg[i]);
		assert(dd.size()==2);
		ll mind = LONG_MAX,maxd=LONG_MIN;
		REP(i,n){
			mind = min(mind,deg[i]);
			maxd = max(maxd,deg[i]);
		}
		assert((maxd==(n-1) || (maxd==2)));
		if(maxd==(n-1)){
			ll ind = -1;
			REP(i,n){
				if(deg[i]==(n-1)){
					ind=i;
					break;
				}
			}
			ll l = (p[0]<p[1]);
			ll r = (p[1]<p[2]);
			ll lesser,greater;
			lesser=ind;
	                greater=n-ind-1;
			if(l && r){
				ans = lesser*greater;
			}
			else if((!l) && r){
	            ans=((greater-1)*greater)/2;
			}
			else if(l && (!r)){
			    ans=((lesser-1)*lesser)/2;
			}
			else
				ans = lesser*greater;
		}
		else if(maxd==2){
			ll ind = -1;
			string order="";
			REP(i,3)
				order += char(p[i]+'0');
			REP(i,n){
				if(deg[i]==1){
					ind = i;
					break;
				}
			}
			v = vector<ll>(n,0);
			dfs(ind);
			st = vector<vector<ll>>(4*n,vector<ll>());
			build(1,0,n-1);
			// for(auto vec: st){
			// 	for(auto it: vec)
			// 		cout << it << " ";
			// 	cout << endl;
			// }
			ll ans=0;
			if(order=="123" || order=="321"){
				FOR(i,1,n-1){
					ll ln = query(1,0,n-1,0,i-1,path[i]);
					ll rn = path[i]-1-ln;
					ans += (ln * (n-i-1 - rn)) + ((i-ln) * rn);
					error(ln,rn,ans);
				}
			}
			else if(order=="132" || order=="231"){
				FOR(i,1,n-1){
					ll ln = query(1,0,n-1,0,i-1,path[i]);
					ll rn = path[i]-1-ln;
					ans += ln*rn;
				}
			}
			else{
				FOR(i,1,n-1){
					ll ln = query(1,0,n-1,0,i-1,path[i]);
					ll rn = path[i]-1-ln;
					ans += (i-ln)*(n-i-1-rn);
				}	
			}
		}
		cout << max(0ll,ans) << endl;
	}
	return 0;
}

