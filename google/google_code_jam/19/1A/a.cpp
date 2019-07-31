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

string suffix(string a,string b){
	string res="";
	ll p1=a.length()-1;
	ll p2=b.length()-1;
	while(p1>=0 && p2>=0){
		if(a[p1]!=b[p2])
			break;
		res = a[p1] + res;
		p1--;
		p2--;
	}
	return res;
}

int main()
{
	fast_io;
	int T;
	cin >> T;
	REP(test,T){
		cout << "Case #" << test+1 << ": ";
		ll n;
		cin >> n;
		if(n>6)
			break;
		vector<string> arr(n);
		REP(i,n)
			cin >> arr[i];
		vector<int> p;
		REP(i,n)
			p.PB(i);
		ll ans=0;
		do{
			set<string> suff;
			REP(i,n){
				if((i+1)>=n)
					break;
				string res = suffix(arr[p[i]],arr[p[i+1]]);
				if(res!="")
					suff.insert(res);
				i++;
			}
			ans = max(ans,2 * (ll)suff.size());
		}while(next_permutation(p.begin(),p.end()));
		cout << ans << endl;
	}
	return 0;
}

