/*=======================
Author    : Shounak Dey
Filename  : 814d.cpp
=======================	*/

#include<bits/stdc++.h>

using namespace std;

typedef int64_t ll;
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

#define PI acos(-1.0)
#define MAXN 1010

//Define structures
typedef struct{
	double x,y;
}point;

typedef struct{
	point c;
	double r;
}circle;

//define data
vector<circle> space(MAXN);
vector<vector<ll>> ch(MAXN,vector<ll>());
vector<ll> parent(MAXN,-1);
vector<ll> color(MAXN,0);

//define functions
int contains(circle a,circle b){
	return ((a.c.x - b.c.x)*(a.c.x - b.c.x) + (a.c.y - b.c.y)*(a.c.y - b.c.y)) <= ((a.r-b.r)*(a.r-b.r)); 
}

void coloring(ll start,ll c){
	color[start] = c;
	for(auto it: ch[start])
		coloring(it,c^1);
	return;
}

int main()
{
	fast_io;
	ll n;
	cin >> n;
	auto area = [](circle a){
		return PI * a.r * a.r;
	};
	REP(i,n)
		cin >> space[i].c.x >> space[i].c.y >> space[i].r;
	REP(i,n){
		parent[i] = -1;
		REP(j,n){
			if(space[j].r>space[i].r && contains(space[j],space[i])){
				if(parent[i]==-1 || space[parent[i]].r>space[j].r) 
					parent[i]=j;
			}
		}
		if(parent[i]!=-1)
			ch[parent[i]].PB(i);
	}	
	double ans=0;
	REP(i,n){
		if(parent[i]==-1)
			coloring(i,0);
	}
	REP(i,n)
		ans += ((parent[i]==-1 || color[i])?1 : -1)*space[i].r*space[i].r;
	cout << setprecision(15) << fixed;
	cout << ans * PI << endl;
	return 0;
}