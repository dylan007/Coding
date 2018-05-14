//Shounak Dey
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

#define MOD 1000000007
#define END 100005

int f(int k,int s,int n)
{
	return (k*((n+1)-((s*(k+1))/2)))%MOD;
}

int main()
{
	int t,k;
	read(t);read(k);
	vector<int> vals(END,1);
	vals[0]=0;
	FOR(i,1,END)
	{
		int p = i/k - ((i%k) == 0);
		vals[i] = (vals[i] + (i%k == 0)+f(p,k,i))%MOD;
//		if(i<=10)
//			cout << p << " " << vals[i] << " " << i << endl;
	}
	FOR(i,1,END)
		vals[i] = (vals[i]+vals[i-1])%MOD;
	int x,y;
	/*FOR(i,1,10)
		cout << vals[i] << " ";
	cout << endl;
*/	while(t--)
	{
		cin >> x >> y;
		cout << (vals[y]-vals[x-1]+MOD)%MOD << endl;
	}
	return 0;
}

