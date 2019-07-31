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

vector<vector<ll>> dep;
vector<ll> visited;
ll cycle=0;
string out="";
stack<ll> s;
vector<ll> parent(27),size(27,1);

void dfs(ll start){
	visited[start] = 1;
	REP(i,27){
		if(dep[start][i]){
			if(visited[i]){
				cycle=1;
				return;
			}
			dfs(i);
		}
	}
	return;
}

void topo(ll start){
	visited[start] = 1;
	REP(i,27){
		if(dep[start][i] && (!visited[i]))
			topo(i);
	}
	s.push(start);
	return;
}

ll find(ll x){
	if(parent[x] != x)
		parent[x] = find(parent[x]);
	return parent[x];
}

int main()
{
	fast_io;
	ll n;
	cin >> n;
	vector<string> arr(n);
	REP(i,27)
		parent[i]=i;
	REP(i,n)
		cin >> arr[i];
	ll ans=1;
	dep = vector<vector<ll>>(27,vector<ll>(27,0));
	vector<ll> indeg(27,0);
	REP(i,n-1){
		string a,b;
		a = arr[i];
		b = arr[i+1];
		ll f=-1;
		REP(i,min(a.length(),b.length())){
			if(a[i]!=b[i]){
				f=i;
				break;
			}
		}
		if(f==-1){
			if(a.length()>b.length()){
				ans=0;
				break;
			}
		}
		else{
			dep[a[f]-'a'+1][b[f]-'a'+1]=1;
			indeg[b[f]-'a'+1]++;
		}
	}
	/*visited = vector<ll>(26,0);
	REP(i,26){
		if(visited[i])
			continue;
		dfs(i);
	}
	visited = vector<ll>(26,0);
	if(cycle || (ans==0)){
		cout << "Impossible" << endl;
		return 0;
	}*/
	FOR(i,1,27){
		if(indeg[i]==0)
		dep[0][i] = 1;
	}
	visited = vector<ll>(27,0);
	REP(i,27){
		if(visited[i])
			continue;
		topo(parent[i]);
		while(!s.empty()){
			if(s.top()!=0)
				out += (s.top() + 'a'-1);
			s.pop();
		}
	}
	vector<ll> pos(26,0);
	REP(i,26)
		pos[out[i]-'a']=i;
	cycle=0;
	//cout << out << endl;
	FOR(i,1,27){
		FOR(j,1,27){
			if(dep[i][j] && (pos[i-1]>pos[j-1])){
				//cout << char('a'+i-1) << " " << char('a'+j-1) << endl;
				cycle=1;
				break;
			}
		}
	}
	if(cycle || (ans==0))
		out = "Impossible";
	cout << out << endl;
	return 0;
}

