/*=======================
Author    : Shounak Dey
Filename  : solution.cpp
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

#define MAX (double)(1e18)

typedef struct point{
	double x,y;
	bool operator <(const point &pt) const{
		if(x==pt.x)
			return y<pt.y;
		return x<pt.x;
	}
}point;

int main()
{
	fast_io;
	//Init.
	ll n;
	cin >> n;
	vector<point> ps(n);
	vector<ll> arr(n);
	REP(i,n)
		cin >> arr[i];
	ps[0].y = arr[0];
	ps[0].x = 0;
	FOR(i,1,n){
		ps[i].x = i;
		ps[i].y = ps[i-1].y + arr[i];
		arr[i] += arr[i-1];
	}
	double curr = MAX;
	auto dist = [](point a,point b){
		return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
	};

	//Sort according to x and the y. 
	sort(ps.begin(),ps.end(),[](point a,point b){
		if(a.x == b.x)
			return a.y < b.y;
		return a.x < b.x;
	});
	
	for(auto it: ps)
		cout << it.x << " " << it.y << endl;

	//Create a bounding box.
	set<point> box;
	box.insert(ps[0]);
	ll left=0,pos1,pos2;

	//Iterate through all points and adjust bounding box accordingly.
	FOR(i,1,n){
		while(left<i && ((ps[i].x-curr)>(ps[left].x)))
			box.erase(ps[left++]);
		point tmp;
		tmp.x = ps[i].x - curr;
		tmp.y = ps[i].y - curr;
		for(auto it=box.lower_bound(tmp);it!=box.end() && (it->y <= (ps[i].y+curr));it++){
			ll tmp = dist(*it,ps[i]);
			error(tmp,(*it).x,ps[i].x);
			if(tmp < curr){
				pos1 = (*it).x;
				pos2 = ps[i].x;
				curr = tmp;
			}
		}
		// error(i,curr);
		box.insert(ps[i]);
	}
	cout << (pos1-pos2)*(pos1-pos2) + (arr[pos1]-arr[pos2])*(arr[pos1]-arr[pos2]) << endl;
	return 0;
}