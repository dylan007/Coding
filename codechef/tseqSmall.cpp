/*=======================
Author    : Shounak Dey
Filename  : tseqSmall.cpp
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

vector<ll> w;
vector<ll> path;

vector<ll> euler;
vector< vector< ll > > adj;
vector<ll> visited;
vector<ll> st;
vector<ll> d;
vector<ll> ed;

void dfs(ll start){
    visited[start]=1;
    euler.PB(start);
    for(auto it:adj[start]){
        if(visited[it])
            continue;
        dfs(it);
        euler.PB(start);
    }
    return;
}

void bfs2(ll start){
    queue<ll> q;
    q.push(start);
    d[start]=0;
    while(!q.empty()){
        ll curr = q.front();
        q.pop();
        visited[curr] = 1;
        for(auto it:adj[curr]){
            if(visited[it])
                continue;
            d[it] = d[curr]+1;
            q.push(it);
        }
    }
}

void build(ll curr,ll l, ll r){
    if(l==r){
        st[curr]=ed[l];
        return;
    }
    ll mid = (l+r)>>1;
    ll left = curr<<1;
    ll right = left|1;
    build(left,l,mid);
    build(right,mid+1,r);
    st[curr] = min(st[left],st[right]);
}

ll query(ll curr,ll i,ll j, ll l,ll r){
    if((i>r) || (j<l))
        return -1;
    if((i>=l) && (j<=r))
        return st[curr];
    ll mid = (i+j)>>1;
    ll left = query(curr<<1,i,mid,l,r);
    ll right = query((curr<<1)|1,mid+1,j,l,r);
    if(left==-1)
        return right;
    if(right==-1)
        return left;
    return min(left,right);
}

void bfs(ll start, ll end, ll n){
	vector<ll> visited2(n,0);
	queue<ll> q;
	q.push(start);
	vector<ll> parent(n,-1);
	while(!q.empty()){
		ll curr = q.front();
		q.pop();
		visited2[curr] = 1;
		for(auto it:adj[curr]){
			if(!visited2[it]){
				parent[it] = curr;
				q.push(it);
			}
		}
	}
	ll curr = end;
	while(parent[curr]!=-1){
		path.PB(w[curr]);
		curr = parent[curr];
	}
	path.PB(w[start]);
}

vector<ll> fact(20000010,0);

#define MOD 1000000007

ll modexp(ll a,ll b){
	if(a<=0)
		return 0ll;
    ll ans=1;
    while(b){
        if(b&1)
            ans = (ans * a)%MOD;
        a = (a * a)%MOD;
        b >>= 1;
    }
    return ans;
}

ll modinv(ll a){
    return modexp(a,MOD-2);
}


ll nCr(ll a,ll b){
    if(a<b)
        return 0;
    // assert(a<fact.size());
    // assert(b<fact.size());
    ll ans = fact[a];
    ans = (ans * modinv(fact[b]))%MOD;
    ans = (ans * modinv(fact[a-b]))%MOD;
    return ans;
}

int main()
{
	fast_io;
	fact[0] = 1;
    FOR(i,1,fact.size())
        fact[i] = (fact[i-1]*i)%MOD;
	ll n,q;
	cin >> n >> q;
	if((n<=1000) && (q<=1000)){
		w = vector<ll>(n);
		REP(i,n)
			cin >> w[i];
		adj = vector<vector<ll>>(n,vector<ll>());
		REP(i,n-1){
			ll x,y;
			cin >> x >> y;
			x--;y--;
			adj[x].PB(y);
			adj[y].PB(x);
		}
		while(q--){
			string s;
			cin >> s;
			if(s=="UPDATE"){
				ll u,x;
				cin >> u >> x;
				u--;
				w[u] = x;
			}
			else{
				ll u,v,a,b;
				cin >> u >> v >> a >> b;
				path = vector<ll>();
				u--;v--;
				bfs(u,v,n);
				reverse(path.begin(),path.end());
				// for(auto it: path)
				// 	cout << it << " ";
				// cout << endl;
				// error(s);
				ll f=1;
				vector<ll> tmp;
				for(auto it: path){
					if(it!=-1)
						tmp.PB(it);
				}
				if(s=="INCREASING" && (tmp.size()>0)){
					ll curr=tmp[0];
					FOR(i,1,tmp.size()){
						if(tmp[i]<=curr){
							f=0;
							break;
						}
						curr = tmp[i];
					}
				}
				else if(s=="DECREASING" && (tmp.size()>0)){
					ll curr=tmp[0];
					FOR(i,1,tmp.size()){
						if(tmp[i]>=curr){
							f=0;
							break;
						}
						curr = tmp[i];
					}
				}
				else if(s=="NON-INCREASING"  && (tmp.size()>0)){
					ll curr=tmp[0];
					FOR(i,1,tmp.size()){
						if(tmp[i]>curr){
							f=0;
							break;
						}
						curr = tmp[i];
					}
				}
				else if(s=="NON-DECREASING" && (tmp.size()>0)){
					ll curr=tmp[0];
					FOR(i,1,tmp.size()){
						if(tmp[i]<curr){
							f=0;
							break;
						}
						curr = tmp[i];
					}
				}
				// error(f);
				if(!f){
					cout << 0 << endl;
					continue;
				}
				ll ans=1;
				ll l;
				if(s=="INCREASING" || s=="NON-DECREASING")
					l = (path[0]==-1)?-1:path[0];
				else
					l = (path[0]==-1)?2*b:path[0];
				ll neg = (path[0]==-1);
				vector<pair<ll,ll>> range;
				vector<ll> c;
				ll len = (path[0]==-1);
				FOR(i,1,path.size()){
					if(path[i]!=-1){
						if(neg){
							range.PB(MK(l,path[i]));
							c.PB(len);
							len = 0;
						}
						l = path[i];
					}
					else{
						if(!neg)
							len = 0;
						len++;
					}
					neg = (path[i]==-1);
				}
				if(path[path.size()-1]==-1){
					if(s=="INCREASING" || s=="NON-DECREASING")
						range.PB(MK(l,2*b));
					else
						range.PB(MK(l,-1));
					// range.PB(MK(l,2*b));
					c.PB(len);
				}
				if(s=="INCREASING"){
					ans = 1;
					REP(i,range.size()){
						ll l = range[i].first+1;
						ll r = range[i].second-1;
						l = max(l,a);
						r = min(r,b);
						ans = (ans * nCr(r-l+1,c[i]))%MOD;
					}
				}
				else if(s=="DECREASING"){
					ans = 1;
					REP(i,range.size()){
						ll l = range[i].first-1;
						ll r = range[i].second+1;
						l = min(l,b);
						r = max(r,a);
						ans = (ans * nCr(l-r+1,c[i]))%MOD;
					}
				}
				else if(s=="NON-INCREASING"){
					ans = 1;
					REP(i,range.size()){
						ll l = range[i].first;
						ll r = range[i].second;
						l = min(l,b);
						r = max(r,a);
						ans = (ans * nCr(l-r+1+c[i]-1,c[i]))%MOD;
					}
				}
				else{
					ans = 1;
					REP(i,range.size()){
						ll l = range[i].first;
						ll r = range[i].second;
						l = max(l,a);
						r = min(r,b);
						ans = (ans * nCr(r-l+1+c[i]-1,c[i]))%MOD;
					}	
				}
				cout << ans << endl;
			}
		}
	}
	else{
		vector<ll> w(n);
	    REP(i,n)
	        cin >> w[i];
	    visited = vector<ll>(n,0);
	    adj = vector<vector< ll > > (n,vector<ll>());
	    REP(i,n-1){
	        ll x,y;
	        cin >> x >> y;
	        x--;y--;
	        adj[x].PB(y);
	        adj[y].PB(x);
	    }
	    dfs(0);
	    visited = vector<ll>(n,0);
	    d = vector<ll>(n,0);
	    bfs2(0);
	    ll pl = euler.size();
	    ed = vector<ll>(pl,0);
	    REP(i,pl)
	        ed[i] = d[euler[i]];
	    st = vector<ll>(4 * pl,0);
	    // cout << "DONE" << endl;
	    build(1,0,pl-1);
	    unordered_map<ll,ll> fa;
	    REP(i,pl){
	        if(fa.find(euler[i])==fa.end())
	            fa[euler[i]]=i;
	    }
	    // for(auto it:euler)
	    //     cout << it << " ";
	    // cout << endl;
	    // for(auto it: ed)
	    //     cout << it << " ";
	    // cout << endl;
	    // for(auto it: st)
	    //     cout << it << " ";
	    // cout << endl;
	    while(q--){
	        string seq;
	        cin >> seq;
	        ll u,v,a,b;
	        if(seq=="UPDATE"){
	            cin >> u >> v;
	            continue;
	        }
	        else
	            cin >> u >> v >> a >> b;
	        u--;
	        v--;
	        if(fa[u]>fa[v])
	            swap(u,v);
	        // assert(1==2);
	        // error(u,v,fa[u],fa[v]);
	        // cout << ed[query(fa[u],fa[v])] << endl;
	        // cout << query(1,0,pl-1,fa[u],fa[v]) << endl;
	        ll dist = d[u] + d[v] - 2*query(1,0,pl-1,fa[u],fa[v]);
	        if(seq=="INCREASING" || seq=="DECREASING"){
	            // assert((b-a+1) <= 100000000);
	            // assert((dist+1) <= 100000000);
	            cout << nCr(b-a+1,dist+1) << endl;
	        }
	        else{
	            // assert((b-a+1 + dist) <= 100000000);
	            // assert((dist+1) <= 100000000);
	            cout << nCr(b-a+1 + dist,dist+1) << endl;
	        }
	        // cout << -1 << endl;
	    }
	}
	
	return 0;
}