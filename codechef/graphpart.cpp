/*=======================
Author    : Shounak Dey
Filename  : graphpart.cpp
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
			ll x,y;
			cin >> x >> y;
			x--;y--;
			adj[x].PB(y);
			adj[y].PB(x);
		}
		vector<ll> level(n,0);
		vector<ll> color(n,-1);
		queue<ll> q;
		q.push(0);
		color[0] = 0;
		while(!q.empty()){
			ll curr = q.front();
			q.pop();
			for(auto it:adj[curr]){
				if(color[it]!=-1)
					continue;
				q.push(it);
				level[it] = level[curr]+1;
				color[it] = color[curr]^1;
			}
		}
		ll c1=0,c0=0;
		for(auto it:color)
			c1 += it;
		c0 = n-c1;
		//Represent excess set by 1.
		if(c1<(n/2)){
			REP(i,n)
				color[i] ^= 1;
			c0 = c1 + c0;
			c1 = c0 - c1;
			c0 -= c1;
		}
		// for(auto it: lv){
		// 	for(auto its: it)
		// 		cout << its << " ";
		// 	cout << endl;
		// }
		if(c0==c1){
			cout << 1 << endl;
			REP(i,n){
				if(color[i]==0)
					cout << i+1 << " "; 
			}
			cout << endl;
			REP(i,n){
				if(color[i])
					cout << i+1 << " ";
			}
			cout << endl;
		}
		else{
			vector<vector<ll>> lv1(n,vector<ll>());
			REP(i,n){
				if(color[i])
					lv1[level[i]>>1].PB(i);
			}
			sort(lv1.begin(),lv1.end(),[](vector<ll> a,vector<ll> b){
				return a.size() > b.size();
			});
			vector<ll> endp;
			ll pos = 0,lpos=0;
			while(c0<c1){	
				if(lv1[pos].size()>1 && (lpos+1)<lv1[pos].size()){
					color[lv1[pos][lpos]] ^=1;
					c0++;
					c1--;
					lpos++;
				}
				else{
					if(lv1[pos].size()>0)
						endp.PB(lv1[pos][lv1[pos].size()-1]);
					lpos=0;
					pos++;
				}
			}
			pos=0;
			while(c0<c1 && pos<(endp.size()-1)){
				color[endp[pos++]] ^= 1;
				c0++;
				c1--;
			}
			cout << 2 << endl;
			REP(i,n)
				if(color[i]) cout << i+1 << " ";
			cout << endl;
			REP(i,n)
				if(!color[i]) cout << i+1 << " ";
			cout << endl;
		}
	}
	return 0;
}