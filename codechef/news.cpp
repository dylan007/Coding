/*=======================
Author    : Shounak Dey
Filename  : news.cpp
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

pair<ll,ll> update(pair<ll,ll> pos,char dir,ll v){
	if(dir=='N')
		pos.second += v;
	else if(dir=='S')
		pos.second -= v;
	else if(dir=='E')
		pos.second += v;
	else
		pos.second -= v;
	return pos;
}

int main()
{
	TEST{
		ll n,v1,v2;
		cin >> n >> v1 >> v2;
		pair<ll,ll> pos;
		pos.first = pos.second = 0;
		string s;
		cin >> s;
		ll state=0;
		REP(i,n){
			if(s[i]=='*')
				state ^= 1;
			else if(state)
				pos = update(pos,s[i],v2);
			else
				pos = update(pos,s[i],v1);
		}
		// cout << pos.first << " " << pos.second << endl;
		pos.first = max(pos.first,0-pos.first);
		pos.second = max(pos.second,0-pos.second);
		ll m = min(pos.first,pos.second);
		if(m&1){
			if(pos.first == pos.second)
				cout << "W" << endl;
			else if(pos.first > pos.second){
				pos.first -= pos.second;
				if(pos.first & 1)
					cout << "B" << endl;
				else
					cout << "W" << endl;
			}
			else{
				pos.second -= pos.first;
				if(pos.second & 1)
					cout << "B" << endl;
				else
					cout << "W" << endl;
			}
		}
		else{
			if(pos.first == pos.second)
				cout << "B" << endl;
			else if(pos.first > pos.second){
				pos.first -= pos.second;
				if(pos.first & 1)
					cout << "W" << endl;
				else
					cout << "B" << endl;
			}
			else{
				pos.second -= pos.first;
				if(pos.second & 1)
					cout << "W" << endl;
				else
					cout << "B" << endl;
			}
		}
	}
	return 0;
}