/*=======================
Author    : Shounak Dey
Filename  : gopher.cpp
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

int check(vector<vector<int>> marked,int x,int y){
	x-=9;y-=9;
	for(int i=x-1;i<=(x+1);i++){
		for(int j=(y-1);j<=(y+1);j++){
			if(marked[j][i]==0)
				return 0;
		}
	}
	return 1;
}

int checkleft(vector<vector<int>> marked,int x,int y){
	x-=9;y-=9;
	for(int i=(y-1);i<=(y+1);i++){
		if(marked[i][x-1]==0)
			return 0;
	}
	return 1;
}

int main()
{
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<vector<int>> marked(3,vector<int>(200,0));
		int x=10,y=10;
		int tries=1000;
		while(tries--){
			while(check(marked,x,y)){
				x++;
			}
			if(checkleft(marked,x,y))
				x++;
			cout << x << " " << y << endl << flush;
			int px,py;
			cin >> px >> py;
			if(px==-1 && py==-1)
				break;
			else if(px==0 && py==0)
				break;
			marked[py-9][px-9]=1;
		}
	}
	return 0;
}
