/*=======================
Author    : Shounak Dey
Filename  : dldag.cpp
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
	ll n,m;
	cin >> n >> m;
	vector<vector<ll>> in(n,vector<ll>());
	vector<ll> outdeg(n,0);
	vector<pair<ll,ll>> ans;
	REP(i,m){
		ll x,y;
		cin >> x >> y;
		x--;y--;
		in[y].PB(x);
		outdeg[x]++;
	}
	auto comp = [](pair<ll,ll> lhs,pair<ll,ll> rhs){
		return lhs.second > rhs.second;
	};	
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,decltype(comp)> q(comp);
	REP(i,n){
		if(outdeg[i]==0)
			q.push({i,outdeg[i]});
	}
	vector<ll> disc(n,0);
	ll rem=n;
	while(!q.empty()){
		auto n1 = q.top();
		q.pop();
		if(disc[n1.first])
			continue;
		for(auto it: in[n1.first]){
			if(disc[it])
				continue;
			outdeg[it]--;
			if(outdeg[it]==0)
				q.push({it,outdeg[it]});
		}
		disc[n1.first]=1;
		rem--;
		if(q.empty()){
			// cout << "Empty Queue" << endl;
			ans.PB({n1.first+1,-1});
			// cout << 1 << " " << n1.first+1 << endl;
			break;
		}
		auto n2 = q.top();
		while(1){
			if(disc[n2.first])
				q.pop();
			else
				break;
			n2 = q.top();
		}
		if(n2.second > 0){
			// cout << "No other vertex with 0 outdegree" << endl;
			ans.PB({n1.first+1,-1});
			// cout << 1 << " " << n1.first+1 << endl;
			for(auto it: in[n1.first]){
				if(disc[it])
					continue;
				outdeg[it]--;
				if(outdeg[it]==0)
					q.push({it,outdeg[it]});
			}
		}
		else{
			ll f=0;
			for(auto it: in[n1.first]){
				if(it==n2.first)
					f=1;
			}
			if(!f){
				q.pop();
				disc[n2.first]=1;
				rem--;
				// cout << 2 << " " << n1.first+1 << " " << n2.first+1 << endl;
				ans.PB({n1.first+1,n2.first+1});
				for(auto it: in[n2.first]){
					if(disc[it])
						continue;
					outdeg[it]--;
					if(outdeg[it]==0)
						q.push({it,outdeg[it]});
				}
			}
			else{
				// cout << "There exists an edge" << endl;
				// cout << 1 << " " << n1.first+1 << endl;
				ans.PB({n1.first+1,-1});
			}
		}
		// for(auto it: outdeg)
		// 	cout << it << " ";
		// cout << endl;
		// for(auto it: disc)
		// 	cout << it << " ";
		// cout << endl;
		// cout << q.empty() << endl;	
	}
	cout << ans.size() << endl;
	for(auto it: ans){
		if(it.second == -1)
			cout << 1 << " " << it.first << endl;
		else
			cout << 2 << " " << it.first << " " << it.second << endl;
	}
	return 0;
}