/*=======================
Author    : Shounak Dey
=======================*/
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
#define TEST int Test;cin >> Test;while(Test--):
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

void mul(vector<vector<ll>> &a,vector<vector<ll>> b){
    vector<vector<ll>> c(a.size(),vector<ll>(a.size(),0));
    ll n = a.size();
    REP(i,n){
        REP(j,n){
            REP(k,n)
                c[i][j] += a[i][k] * b[k][j];
        }
    }
    REP(i,n) REP(j,n) a[i][j] = c[i][j];
}

void modexp(vector<ll>)

int main()
{
    fast_io;
    vector<vector<ll>> a(3,vector<ll>(3,0));
    a[0][0] = a[0][1] = a[0][2] = a[1][0] = a[2][1] = 1;

    return 0;
}