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

vector<ll> outpath;

ll id(ll r,ll c,ll x,ll y){
	return c*x + y;
}

void printC(ll r,ll c,ll id){
	cout << (id/c)+1 << " " << (id%c)+1 << endl;
}

int check(ll r,ll c,ll r1,ll c1){
	if(r==r1) return 0;
	if(c==c1) return 0;
	if((r+c)==(r1+c1)) return 0;
	if((r-c)==(r1-c1)) return 0;
	return 1;
}

int alld(vector<ll> visited){
	for(auto it:visited){
		if(!it)
			return 0;
	}
	return 1;
}

int dfs(vector<vector<ll>> adj,vector<ll> path,ll start,vector<ll> visited,ll c=0){
	visited[start] = 1;
	path.PB(start);
	int flag=0;
	c++;
	if(c == visited.size()){
		outpath = path;
		return 1;
	}
	for(auto it:adj[start]){
		if(!visited[it])
			flag |= dfs(adj,path,it,visited,c);
	}
	return flag;
}

int main()
{
	fast_io;
	ll T;
	cin >> T;
	REP(test,T){
		cout << "Case #" << test+1 << ": ";
		ll r,c;
		cin >> r >> c;
		vector<vector<ll>> adj(r*c,vector<ll>());
		REP(i,r){
			REP(j,c){
				REP(k,r){
					REP(l,c){
						if(check(i,j,k,l)){
							adj[id(r,c,i,j)].PB(id(r,c,k,l));
							adj[id(r,c,k,l)].PB(id(r,c,i,j));
						}
					}
				}
			}
		}
		cout << "Done" << endl;
		int ans=0;
		vector<ll> parent(r*c);
		REP(i,r){
			REP(j,c){
				vector<ll> visited(r*c,0);
				vector<ll> path;
				int res = dfs(adj,path,id(r,c,i,j),visited);
				ans |= res;
				if(ans)
					break;
			}
		}
		if(ans){
			cout << "POSSIBLE" << endl;
			for(auto it:outpath){
				printC(r,c,it);
			}
		}
		else
			cout << "IMPOSSIBLE" << endl;
	}
	return 0;
}

