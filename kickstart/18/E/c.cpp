/*=======================
Author    : Shounak Dey
Filename  : c.cpp
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

int calc(vector<int> a,vector<int> b){
	int l = a.size()/3;
	int ans=0;
	REP(i,(a.size()/l)){
		int c1=0,c2=0;
		FOR(j,i*l,i*l+l){
			c1 += a[j];
			c2 += b[j];
		}
		ans += (c1>c2);
	}
	return ans>1;
}

int main()
{
	int T;
	cin >> T;
	REP(t,T){
		int n;
		cin >> n;
		n*=3;
		vector<int> a(n),b(n);
		REP(i,n)
			cin >> a[i];
		REP(i,n)
			cin >> b[i];
		SORTV(a);
		SORTV(b);
		double c=0,tot=0,ans=0.0;
		set<pair<vector<int>,vector<int>>> check;
		set<vector<int>> x;
		do{
			vector<int> cpa(a),temp(b);
			REP(i,3)
				sort(cpa.begin()+3*i,cpa.begin()+3*i+3);
			c = tot = 0;
			if(x.find(cpa)==x.end()){
				x.insert(cpa);
				do{
					if(calc(cpa,temp))
						c++;
					tot++;
				}while(next_permutation(temp.begin(),temp.end()));
				if(tot>0){
					// error(c,tot,c/tot);
					ans = ans>(c/tot)?ans:(c/tot);
				}
			}
		}while(next_permutation(a.begin(),a.end()));
		cout << setprecision(8) << fixed;
		cout << "Case #" << t+1 << ": " << ans << endl;
	}
	return 0;
}