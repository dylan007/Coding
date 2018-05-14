/*=======================
Author    : Shounak Dey
Filename  : q1.cpp
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
	int T;
	cin >> T;
	for(int t=0;t<=T;t++){
		cout << "Case #" << t+1 << ": ";
		double n,l;
		cin >> n >> l;
		vector<double> arr(int(l),0);
		vector<double> rup;
		int ans=0;
		int m = 0;
		double r=0;
		double x;
		int tot=0;
		REP(i,int(l)){
			cin >> arr[i];
			tot += arr[i];
			int d = (arr[i]/n)*100;
			if(((arr[i]/n)*100 - d)>=0.5){
				if(r > (1 - (arr[i]*100)/n + d)){
					r = 1 - (arr[i]*100)/n + d;
					x = d+1;
				}
				else if(r == (1 - (arr[i]*100)/n + d))
					x = max(x,double(d+1));
				rup.PB(1 - (arr[i]*100)/n + d);
				ans += (arr[i])*(d+1);
			}
			else{
				ans += (arr[i])*d;
				m = max(m,d);
			}
		}
		SORTV(rup);
		// cout << endl;
		// for(auto it:rup)
		// 	cout << it << " ";
		// cout << endl;
		if(rup.size()>0)
			ans += (x)*(n-tot);
		else{
			cout << ans << endl;
			cout << m << " " << tot << endl;
			ans += m*(n-tot);
		}
		cout << ans << endl;
	}
	return 0;
}
