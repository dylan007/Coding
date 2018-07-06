/*=======================
Author    : Shounak Dey
Filename  : lazyprog.cpp
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
		int n;
		read(n);
		cout << setprecision(10) << fixed;
		vector<pair<double,pair<double,double>>> works;
		vector<pair<pair<double,double>,int>> intcost;
		REP(i,n){
			double a,b,d;
			cin >> a >> b >> d;
			works.PB(MK(d,MK(a,b)));
			intcost.PB(MK(MK(d,b/a),i));
		}
		if(n==1){
			cout << 0.00 << endl;
			continue;
		}
		sort(intcost.begin(),intcost.end(),[](const auto &lhs,const auto &rhs){
			if(lhs.first.first == rhs.first.first)
				return lhs.first.second < rhs.first.second;
			return lhs.first.first < rhs.first.first;
		});
		// for(auto it: intcost){
		// 	cout << it.first.first << " " << it.first.second << endl; 
 	// 	}
 		double cost=0;
 		int curr=0;
 		while(curr < (n-1)){
 			double x = intcost[curr].first.first;
 			double y = intcost[curr+1].first.first;
 			double diff = y-x;
 			if(diff == 0){
 				cost += intcost[curr].first.second;	
 			}
 			else{
 				double a,b;
 				int index = intcost[curr].second;
 				a = works[index].second.first;
 				b = works[index].second.second;
 				// error(b,diff,curr);
 				if(b > diff)
 					cost += (b - diff)/a;
 			}
 			// error(diff,cost);
 			curr++;
 		}
 		cout << cost << endl;
	}
	return 0;
}