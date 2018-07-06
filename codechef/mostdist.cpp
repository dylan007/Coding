/*=======================
Author    : Shounak Dey
Filename  : mostdist.cpp
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

ull dist(ull x,ull y,pair<ull,ull> p){
	return max(p.first,x)-min(p.first,x) + max(p.second,y)-min(p.second,y);	
}

int main()
{
	ull q;
	cin >> q;
	ull curr=0;
	ull answer = 0;
	map<ull,pair<ull,ull>> query;
	set<pair<ull,ull>> s;
	map<pair<ull,ull>,ull> count;
	while(q--){
		string c;
		cin >> c;
		if(c=="+"){
			ull x,y;
			cin >> x >> y;
			x = x^answer;
			y = y^answer;
			// error(x,y);
			curr++;
			query[curr] = MK(x,y); 
			s.insert(MK(x,y));
			if(count.find(MK(x,y)) != count.end())
				count[MK(x,y)]++;
			else
				count[MK(x,y)] = 1;
		}
		else if(c=="-"){
			ull p;
			cin >> p;
			p = p^answer;
			// error(p);
			count[query[p]]--;
			if(count[query[p]] == 0)
				s.erase(query[p]);
		}
		else{
			pair<ull,ull> p1,p2;
			p1 = *(s.begin());
			p2 = *(s.rbegin());
			ull x,y;
			cin >> x >> y;
			x ^= answer;
			y ^= answer;
			// error(x,y);
			// cout << p1.first << " " << p1.second << " " << p2.first << " " << p2.second << endl;
			ull d1,d2;
			d1 = dist(x,y,p1);
			d2 = dist(x,y,p2);
			cout << max(d1,d2) << endl;
			answer = max(d1,d2);
		}
	}
	return 0;
}