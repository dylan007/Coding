/*=======================
Author    : Doraemon
File      : densegrp
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

using pll = pair<ll,ll>;
vector<ll> parent;
vector<ll> size;

ll find(ll x){
    if(x == parent[x])
        return x;
    return parent[x] = find(parent[x]);
}

void un(ll x, ll y){
    ll a = find(x);
    ll b = find(y);
    if(a != b){
        if(size[a] < size[b]){
            parent[b] = a;
            size[a] += size[b];
        }
        else{
            parent[a] = b;
            size[b] += size[a];
        }
    }
}

ll cl,cr;

bool overlap(pll r){
    if(cr < r.F)
        return false;
    if(cl > r.S)
        return false;
    cl = min(cl,r.F);
    cr = max(cr,r.S);
    return true;
}

void outputRange(pair<pll,ll> x){
    cout << "Range: " << x.F.F << " " << x.F.S << "\tID: " << x.S;
}

int main()
{
    fast_io;
    TEST{
        ll n,m,x,y;
        cin >> n >> m >> x >> y;
        vector<pair<pll,ll>> ranges;
        parent = vector<ll>(m<<1,0);
        size = vector<ll>(m<<1,1);
        REP(i,parent.size())
            parent[i] = i;
        REP(i,m){
            ll a,b,c,d;
            cin >> a >> b >> c >> d;
            ranges.PB(MK(MK(a,b),i));
            ranges.PB(MK(MK(c,d),i+m));
        }
        sort(ranges.begin(),ranges.end(),[](auto lhs,auto rhs){
            if(lhs.F.F == rhs.F.F)
                return lhs.F.S < rhs.F.S;
            return lhs.F.F < rhs.F.F;
        });
        cl = ranges[0].F.F;
        cr = ranges[0].F.S;
        ll currNode = ranges[0].S;
        FOR(i,1,2*m){
            if(overlap(ranges[i].F))
                un(currNode,ranges[i].S);
            else{
                cl = ranges[i].F.F;
                cr = ranges[i].F.S;
                currNode = ranges[i].S;
            }
            error(cl,cr);
        }
        REP(i,2*m){
            outputRange(ranges[i]);
            cout << "\tParent:" << parent[ranges[i].S] << endl;
        }
    }
    return 0;
}