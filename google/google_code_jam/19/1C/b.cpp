/*=======================
Author    : Shounak Dey
=======================	*/

#include<bits/stdc++.h>

using namespace std;

using ll = long long int;
using ull = unsigned long long int;

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

int main()
{
	fast_io;
	int T,f;
	cin >> T >> f;
	map<string,int> val = {{"A",0},{"B",1},{"C",2},{"D",3},{"E",4}};
	while(T--){
		string res;
		set<int> rem = {0,1,2,3,4};
		vector<vector<int>> pos(5,vector<int>());
		REP(i,119){
			cout << 5*i + 1 << endl << flush;
			cin >> res;
			if(res=="N")
				exit(0);
			pos[val[res]].PB(i);
		}
		int ind;
		vector<int> ans;
		REP(i,5){
			if(pos[i].size()!=24)
				ind = i;
		}
		ans.PB(ind);
		rem.erase(ind);
		//23
		vector<int> cp = pos[ind];
		pos = vector<vector<int>>(5,vector<int>());
			for(auto it: cp){
				cout << 5*it + 2 << endl << flush;
				cin >> res;
				if(res=="N")
					exit(0);
				pos[val[res]].PB(it);
			}
		REP(i,5){
			if((pos[i].size()!=6) && (pos[i].size()>0))
				ind = i;
		}
		ans.PB(ind);
		rem.erase(ind);
		//5
		cp = pos[ind];
		pos = vector<vector<int>>(5,vector<int>());
			for(auto it: cp){
				cout << 5*it+ 3 << endl << flush;
				cin >> res;
				if(res=="N")
					exit(0);
				pos[val[res]].PB(it);
			}
		REP(i,5){
			if((pos[i].size()!=2) && (pos[i].size()>0))
				ind = i;
		}
		ans.PB(ind);
		rem.erase(ind);
		//1
		cp = pos[ind];
		cout << 5*cp[0]+4 << endl << flush;
		cin >> res;
		if(res=="N")
			exit(0);
		ind = val[res];
		rem.erase(ind);
		ans.PB(*(rem.begin()));
		ans.PB(ind);
		string out = "";
		for(auto it:ans)
			out += ('A'+it);
		cout << out << endl << flush;
		cin >> res;
		if(res=="N")
			exit(0);
	}
	return 0;
}

