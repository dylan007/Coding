/*=======================
Author    : Shounak Dey
Filename  : avgmat.cpp
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

int main()
{
	TEST{
		int n,m;
		cin >> n >> m;
		vector<vector<int>> arr(n,vector<int>(m,0));
		vector<pair<int,int>> houses;
		REP(i,n){
			string a;
			cin >> a;
			REP(j,m){
				arr[i][j] = a[j]-'0';
				if(arr[i][j])
					houses.PB(MK(i,j));
			}
		}
		// for(auto it:houses)
		// 	cout << it.first << " " << it.second << endl;
		vector<int> c(n+m-1,0);
		REP(i,houses.size()){
			FOR(j,i+1,houses.size()){
				error(i,j);
				int dist = abs(houses[i].first-houses[j].first) + abs(houses[i].second-houses[j].second);
				c[dist]++;
			}
		}
		FOR(i,1,n+m-1)
			cout << c[i] << " ";
		cout << endl;
	}
	return 0;
}