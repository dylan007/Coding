/*=======================
Author    : Shounak Dey
Filename  : superiorSubstring.cpp
=======================    */

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

ll calc(vector<ll> pos){
    ll ans=3,n=pos.size();
    REP(i,n){
        for(ll j=pos.size()-1;j>i;j--){
            ll c = j-i+1;
            if((2*c+1)<ans)
                break;
            if(c >= (pos[j]-pos[i]+1)>>1){
                ans = max(c*2 + 1,ans);
                break;
            }
        }
    }
    return ans;
}

int main()
{
    fast_io;
    TEST{
        ll n;
        cin >> n;
        string a;
        cin >> a;
        vector<vector<ll>> pos(26,vector<ll>());
        REP(i,n)
            pos[a[i]-'a'].PB(i);
        ll ans=0;
        REP(i,26)
            ans = max(ans,min(n,calc(pos[i])));
        cout << ans << endl;
    }
    return 0;
}