/*=======================
Author    : Shounak Dey
Filename  : 908c.cpp
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

typedef struct{
	double x,y,r;
}circle;

int main()
{
	fast_io;
	ll n,r;
	cin >> n >> r;
	vector<circle> disk(n);
	REP(i,n){
		double x;
		cin >> x;
		disk[i].x = x;
		disk[i].r = r;
		disk[i].y = r;
	}
	vector<circle> fin;
	fin.PB(disk[0]);

	auto place = [r](circle a,circle b){
		return a.y + sqrt(4.0*r*r - (a.x-b.x)*(a.x-b.x));
	};
	FOR(i,1,n){
		double m = r;
		REP(j,fin.size()){
			if(fin[j].x>=(disk[i].x-2*r) && fin[j].x<=(disk[i].x+2*r))
				m = max(m,place(fin[j],disk[i]));
		}
		disk[i].y = m;
		fin.PB(disk[i]);
	}
	cout << setprecision(15) << fixed;
	for(auto it: fin)
		cout << it.y << " ";
	cout << endl;
	return 0;
}