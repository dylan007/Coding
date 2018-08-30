/*=======================
Author    : Shounak Dey
Filename  : b.cpp
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

string conv(int x,int p){
	string out = "";
	REP(i,p){
		if(x&1)
			out += "1";
		else
			out += "0";
		x >>= 1;
	}
	return out;
}

int calc(vector<string> order,string bin){
	int ans=0;
	REP(i,order.size()){
		REP(j,bin.length())
			ans += order[i][j]!=bin[j];
	}
	return ans;
}

int main()
{
	int T;
	cin >> T;
	REP(t,T){
		int n,m,p;
		cin >> n >> m >> p;
		set<string> forbid;
		vector<string> order(n);
		REP(i,n)
			cin >> order[i];
		REP(i,m){
			string temp;
			cin >> temp;
			forbid.insert(temp);
		}
		int limit = (1<<p) - 1;
		int ans = n*p;
		REP(i,limit+1){
			string bin = conv(i,p);
			if(forbid.find(bin) == forbid.end()){
				// if(ans > calc(order,bin))
				// 	cout << bin << endl;
				ans = min(ans,calc(order,bin));
			} 
		}
		cout << "Case #" << t+1 << ": " <<  ans << endl;
	}
	return 0;
}