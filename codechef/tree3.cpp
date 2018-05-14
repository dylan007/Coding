/*=======================
Author    : Shounak Dey
Filename  : tree3.cpp
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
		int n;
		cin >> n;
		vector<vector<pair<int,int>>> adj(n,vector< pair<int,int> >());
		vector<int> degree(n,0);
		REP(i,n-1){
			int x,y;
			cin >> x >> y;
			adj[x-1].PB(MK(y-1,0));
			adj[y-1].PB(MK(x-1,0));
			degree[x-1]++;
			degree[y-1]++;
		}
		if((n-1)%3 == 0){
			cout << "NO" << endl;
			continue;
		}
		queue<int> q;
		REP(i,n){
			REP(j,adj[i].size())
				adj[i][j].second = degree[adj[i][j].first];
			SORTV(adj[i]);
			if(degree[i]==3)
				q.push(i);
		}
		int curr=0;
		vector<vector<int>> ans((n-1)/3);
		while(!q.empty()){
			int p = q.front();
			q.pop();
			ans[curr].PB(p);
			REP(j,adj[p].size()){
				pair<int,int> ne = adj[p][j];
				degree[ne.first]--;
				ne.second--;
				if(degree[ne.first] == 3)
					q.push(ne.first);
				ans[curr].PB(ne.first);
				pair<int,int> temp = MK(p,3);
				adj[ne.first].erase(remove(adj[ne.first].begin(),adj[ne.first].end(),temp),adj[ne.first].end());
			}
			degree[p] -= 3;
			adj[p].erase(adj[p].begin(),adj[p].begin()+3);
			curr++;
		}
		if(curr==ans.size()){
			cout << "YES" << endl;
			REP(i,ans.size()){
				REP(j,4)
					cout << ans[i][j]+1 << " ";
				cout << endl;
			}
		}
		else
			cout << "NO" << endl;
	}
	return 0;
}
