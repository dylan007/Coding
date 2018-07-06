/*=======================
Author    : Shounak Dey
Filename  : cyclical-queries.cpp
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

#define INF -10000000000000000

void dfs(vector<set<pair<ll,ll>>> adj,stack<ll> &toporder,vector<ll> &visited, ll start){
    visited[start] = 1;
    set<pair<ll,ll>>::iterator it = adj[start].begin();
    while(it != adj[start].end()){
        pair<ll,ll> temp = *it;
        if(!visited[temp.first])
            dfs(adj,toporder,visited,temp.first);
       	it++;
    }
    toporder.push(start);
}

int find_farthest(vector<set<pair<ll,ll>>> adj,ll start,ll choice){
    stack<ll> toporder;
    ll n = adj.size();
    vector<ll> visited(n,0);
    // cout << "find_farthest called" << endl; 
    REP(i,n){
        if(!visited[i])
            dfs(adj,toporder,visited,i);
    }
    vector<ll> dist(n,INF);
    dist[start] = 0;
    while(!toporder.empty()){
        ll vertex = toporder.top();
        toporder.pop();
        set<pair<ll,ll>>::iterator it = adj[vertex].begin();
        if(dist[vertex] != INF){
            while(it != adj[vertex].end()){
                if(dist[it->first] < (dist[vertex]+it->second))
                    dist[it->first] = dist[vertex]+it->second;
                it++;
            }
        }
        // cout << vertex << " ";
    }
    // cout << endl;
    ll distance=INF,index=-1;
    REP(i,n){
       if(distance<=dist[i]){
            distance = dist[i];
            index = i;
       }
    }
    // error(index,distance);
    if(choice == 1)
        return index;
    return distance;
}

void clean(vector<set<pair<ll,ll>>> &adj,ll x){
    vector<set<pair<ll,ll>>> cop(adj.size()-1,set<pair<ll,ll>>());
    for(int i=0;i<adj.size() && i!=x;i++){
        set<pair<ll,ll>>::iterator it = adj[i].begin();
        while(it != adj[i].end()){
            pair<ll,ll> temp = *it;
            if(temp.first != x)
                cop[i - (i>x)].insert(temp);
           	it++;
        }
    }
    adj = cop;
}

int main()
{
	ll n;
	cin >> n;
	vector<ll> wt(n);
    vector<set < pair< ll,ll > > > adj(n,set<pair<ll,ll>>());
	REP(i,n){
		cin >> wt[i];
		ll x,y;
		x = i;
		y = (i+1)%n;
		adj[x].insert(MK(y,wt[i]));
	}
	ll m;
    cin >> m;
    while(m--){
        ll c,x;
        cin >> c >> x;
        x--;
        if(c==1){
            ll w;
            cin >> w;
            ll neighbour = (x-1+n)%n;
            adj[neighbour].erase(MK(x,wt[neighbour])); 
            ll y = find_farthest(adj,x,1);
            adj[y].insert(MK(n,w));
            adj[neighbour].insert(MK(x,wt[neighbour]));
            set<pair<ll,ll>> temp;
            adj.PB(temp);
            n++;
        }
        else if(c==2){
            ll w;
            cin >> w;
            adj[x].insert(MK(n,w));
            n++;
        }
        else if(c==3){
            ll y = find_farthest(adj,x,1);
            clean(adj,y);
            // error(adj.size(),n);
            n--;
        }
        else{
            cout << find_farthest(adj,x,2) << endl;
        }
    }
	return 0;
}