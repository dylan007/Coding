/*=======================
Author    : Doraemon
File      : indep
=======================*/

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

#define MAX 500000

int main()
{
    fast_io;
    TEST{
        ll n,m;
        cin >> n >> m;
        vector<vector<ll>> adj(n,vector<ll>());
        REP(i,m){
            ll x,y;
            cin >> x >> y;
            x--;
            y--;
            adj[x].PB(y);
            adj[y].PB(x);
        }
        map<vector<ll>,vector<ll>> groups;
        REP(i,n){
            SORTV(adj[i]);
            if(groups.find(adj[i])==groups.end())
                groups[adj[i]] = vector<ll>();
            groups[adj[i]].PB(i);
        }
        vector<ll> key;
        ll c=0;
        for(auto it: groups){
            if((it.first.size() + it.second.size())==n){
                key = it.first;
                c++;
            }
        }
        // c >>= 1;
        string out = string(n,'1');
        for(auto it:key)
            out[it]--;
        if(c==0)
            out = string(n,'0');
        cout << c << endl;
        cout << out << endl;
    }
    return 0;
}