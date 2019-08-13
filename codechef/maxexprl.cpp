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
	TEST{
		int ni;
		cin >> ni;
		double n = (double)ni;
		vector<double> k(ni),c(ni);
		REP(i,ni)
			cin >> k[i];
		REP(i,ni)
			cin >> c[i];
		double d = 0;
		double factor = k[0];
		REP(i,ni)
			d += c[i] * k[i];
		int flag=0;
		REP(i,ni){
			if((k[i]*d)<0){
				flag=1;
				break;
			}
		}
		if(d==0){
			REP(i,ni){
				if(k[i]*k[0] < 0){
					flag=1;
					break;
				}
			}
		}
		if(flag){
			cout << -1 << endl;
			continue;
		}
		double val = 1;
		REP(i,ni)
			val *= k[i];
		double num = 0;
		REP(i,ni)
			num += (val/k[i]);
		double x1;
		x1 = (d*val)/num;
		assert(x1==0);
		vector<double> ans(ni);
		FOR(i,0,n)
			ans[i] = 1/(k[i]*k[i]);
		double f=0;
		f = (num/val);
		f *= sqrt(x1);
		cout << setprecision(10) << fixed;
		cout << f << " ";
		REP(i,ni)
			cout << (x1/(k[i]*k[i]))-c[i] << " ";
		cout << endl;
	}
	return 0;
}

