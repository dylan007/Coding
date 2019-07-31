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
	int T;
	cin >> T;
	REP(test,T){
		cout << "Case #" << test+1 << ": ";
		int n;
		cin >> n;
		vector<string> a(n);
		REP(i,n)
			cin >> a[i];
		//vector<set<char>> x(500,set<char>());}
		string out="";
		int f=0;
		vector<int> v(n,0);
		auto better = [](char a,char b){
			if((a=='P' && b=='R') || (a=='R' && b=='P'))
				return 'P';
			if((a=='S' && b=='R') || (a=='R' && b=='S'))
				return 'R';
			if((a=='S' && b=='P') || (a=='P' && b=='S'))
				return 'S';
			return a;
		};
		REP(i,500){
			set<char> x;
			REP(j,n){
				if(!v[j])
					x.insert(a[j][i%a[j].length()]);
			}
			if(x.size()==3){
				f=1;
				break;
			}
			else if(x.size()==2){
				vector<char> tmp(x.begin(),x.end());
				out += better(tmp[0],tmp[1]);
				char c = out[out.size()-1];
				REP(k,n){
					if(!v[k] && (c!=a[k][i%a[k].length()]) && (c==better(c,a[k][i%a[k].length()])))
						v[k]=1;
				}
			}
			else{
				auto it = *(x.begin());
				if(it=='R')
					out += "P";
				else if(it=='P')
					out += "S";
				else if(it=='S')
					out += "R";
				char c = out[out.size()-1];
				REP(k,n){
					if(!v[k] && (c==better(c,a[k][i%a[k].length()])))
						v[k] = 1;
				}
			}
		}
		if(f)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << out << endl;
	}
	return 0;
}

