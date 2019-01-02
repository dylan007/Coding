/*=======================
Author    : Shounak Dey
Filename  : nakanj.cpp
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

int bfs(pair<int,int> s,pair<int,int> e){
	queue<pair<int,int>> q;
	q.push(s);
	map<pair<int,int>,int> lev;
	map<pair<int,int>,pair<int,int>> par;
	par[s] = s;
	while(!q.empty()){
		pair<int,int> curr = q.front();
		q.pop();
		if(curr.first<0 || curr.first>=8 || curr.second<0 || curr.second>=8)
			continue;
		if(lev.find(curr) != lev.end())
			continue;
		// cout << curr.first << " " << curr.second << endl;
		if(par[curr] != curr)
			lev[curr] = lev[par[curr]]+1;
		else
			lev[curr]=0;
		int x,y;
		if(curr == e)
			break;
		x = curr.first;
		y = curr.second;
		q.push(MK(x-2,y-1));
		par[MK(x-2,y-1)] = curr;
		q.push(MK(x-1,y-2));
		par[MK(x-1,y-2)] = curr;
		q.push(MK(x+2,y-1));
		par[MK(x+2,y-1)] = curr;
		q.push(MK(x+1,y-2));
		par[MK(x+1,y-2)] = curr;
		q.push(MK(x-2,y+1));
		par[MK(x-2,y+1)] = curr;
		q.push(MK(x-1,y+2));
		par[MK(x-1,y+2)] = curr;
		q.push(MK(x+2,y+1));
		par[MK(x+2,y+1)] = curr;
		q.push(MK(x+1,y+2));
		par[MK(x+1,y+2)] = curr;
	}
	return lev[e];
}

int main()
{
	fast_io;
	TEST{
		string a,b;
		cin >> a >> b;
		pair<int,int> s,e;
		s = MK(a[0]-'a',a[1]-'1');
		e = MK(b[0]-'a',b[1]-'1');
		cout << bfs(s,e) << endl;
	}
	return 0;
}