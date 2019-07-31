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
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

vector<pair<ll,ll>> edges;
vector<vector<ll>> adj;
vector<ll> attacked,edgeIsImportant,nodeAttacked;
vector<ll> visited;
vector<ll> diam;


ll dfs(ll curr){
	visited[curr] = 1;
	int f=0;
	for(auto it:adj[curr]){
		pair<ll,ll> edge = edges[it];
		ll ep = (edge.F == curr)?edge.S:edge.F;
		if(visited[ep])
			continue;
		ll ret = dfs(ep);
		// cout << ret << " " << curr << " " << ep << " " << it << endl;
		edgeIsImportant[it]=ret;
		if(ret)
			f=1;
	}
	if(nodeAttacked[curr])
		f=1;
	return f;
}

ll bfs(ll start){
	queue<ll> q;
	q.push(start);
	visited[start] = 1;
	while(!q.empty()){
		ll curr = q.front();
		q.pop();
		for(auto it: adj[curr]){
			if(!edgeIsImportant[it])
				continue;
			pair<ll,ll> edge = edges[it];
			ll ep = (edge.F == curr)?edge.S:edge.F;
			if(!visited[ep]){
				// cout << curr << " " << ep << " " << visited[ep] << endl;
				visited[ep] = 1;
				diam[ep] += diam[curr]+1;
				q.push(ep);
			}
		}
	}

	// cout << endl << endl;
	// for(auto it: diam)
		// cout << it << " ";
	// cout << endl;
	return max_element(diam.begin(),diam.end())-diam.begin();
}

int main()
{
	fast_io;
	ll n,k;
	cin >> n >> k;
	edges = vector<pair<ll,ll>>(n-1);
	adj = vector<vector<ll>>(n,vector<ll>());
	REP(i,n-1){
		ll x,y;
		cin >> x >> y;
		x--;y--;
		adj[x].PB(i);
		adj[y].PB(i);
		edges[i].F = x;
		edges[i].S = y;
	}	
	vector<ll> attacked(k);
	REP(i,k){
		cin >> attacked[i];
		attacked[i]--;
	}
	edgeIsImportant = vector<ll>(n-1,0);
	nodeAttacked = vector<ll>(n,0);
	// cout << "DONE" << endl;
	REP(i,k)
		nodeAttacked[attacked[i]]=1;
	visited = vector<ll>(n,0);
	dfs(attacked[0]);
	// REP(i,n-1){
	// 	if(edgeIsImportant[i])
	// 		cout << edges[i].F << " " << edges[i].S << endl;
	// }

	ll tot = 0;
	REP(i,n-1)
		tot += edgeIsImportant[i];

	ll ans=LONG_MIN,ind=-1;

	queue<ll> fnodes;

	visited = vector<ll>(n,0);
	diam = vector<ll>(n,0);
	ll fp = bfs(attacked[0]);
	vector<ll> fv(n,0);

	REP(i,n){
		if(diam[fp]==diam[i])
			fnodes.push(i);
	}

	fv[fp]=1;

	diam = vector<ll>(n,0);
	visited = vector<ll>(n,0);
	fp = bfs(fp);
	ll diameter = diam[fp];
	fv[fp]=1;

	REP(i,n){
		if(diam[fp]==diam[i]){
			if(ind==-1)
				ind = i;
			else
				ind = min(ind,(ll)i);
			fnodes.push(i);
		}
	}
	ans = diameter;

	// SORTV(attacked);
	// // SORTV(fnodes);
	// if(n<=1000){
	// 	for(auto node:attacked){
	// 		visited = vector<ll>(n,0);
	// 		diam = vector<ll>(n,0);
	// 		ll farthest = bfs(node);
	// 		ll dist = diam[farthest];
	// 		if(dist>ans){
	// 			ans = dist;
	// 			ind = node;
	// 		}
	// 		else if(dist==ans){
	// 			if(ind==-1)
	// 				ind = node;
	// 			ind = min(ind,node);
	// 		}
	// 	}
	// }
	// else{
		while(!fnodes.empty()){
			ll node = fnodes.front();
			fnodes.pop();
			visited = vector<ll>(n,0);
			diam = vector<ll>(n,0);
			ll farthest = bfs(node);
			vector<ll> ffnodes;
			REP(i,n){
				if(diam[farthest]==diam[i])
					ffnodes.PB(i);
			}
			for(auto it:ffnodes){
				if(!fv[it]){
					fnodes.push(it);
					fv[it]=1;
				}
			}
			farthest = -1;
			for(auto it: ffnodes){
				if(attacked[it])
					farthest = it;
			}
			if(farthest!=-1){
				ll dist = diam[farthest];
				if(dist>ans){
					ans = dist;
					ind = node;
				}
				else if(dist==ans){
					if(ind==-1)
						ind = node;
					ind = min(ind,node);
				}
			}
		}
		// ind = attacked[rand()%(attacked.size())];
	// }
	cout << ind+1 << endl << (2*tot - diameter)*6 << endl;
	return 0;
}

