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

deque<ll> q;

void insert(ll x){
	while(!q.empty() && (q.back()>x))
		q.pop_back();
	q.push_back(x);
}

ll get_min(){
	return q.front();
}

void del(ll x){
	if(!q.empty() && (q.front() == x))
		q.pop_front();
	return;
}

int main()
{
	fast_io;
	ll n,m,a,b;
	cin >> n >> m >> a >> b;
	ll g0,x,y,z;
	cin >> g0 >> x >> y >> z;
	vector<vector<ll>> arr(n,vector<ll>(m,0));
	REP(i,n){
		REP(j,m){
			arr[i][j] = g0;
			g0 = (g0 * x + y) % z;
		}
	}
	ll nr,mr;
	nr = n-a+1;
	mr = m-b+1;
	vector<vector<ll>> rowm(n,vector<ll>(mr,0));
	REP(i,n){
		q = deque<ll>();
		ll cr=0;
		REP(j,b)
			insert(arr[i][j]);
		rowm[i][cr]=q.front();
		cr++;
		FOR(j,b,m){
			insert(arr[i][j]);
			del(arr[i][j-b]);
			rowm[i][cr]=q.front();
			cr++;
		}
	}
	vector<vector<ll>> mn(nr,vector<ll>(mr,0));
	ll ans=0;
	REP(j,mr){
		q = deque<ll>();
		ll cr=0;
		REP(i,a)
			insert(rowm[i][j]);
		mn[cr][j] = get_min();
		ans += mn[cr][j];
		cr++;
		FOR(i,a,n){
			insert(rowm[i][j]);
			del(rowm[i-a][j]);
			mn[cr][j]=q.front();
			ans += mn[cr][j];
			cr++;
		}
	}
	cout << ans << endl;
	return 0;
}

