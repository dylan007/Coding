/*=======================
Author    : Shounak Dey
File      : 1367b
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

int main()
{
    fast_io;
    TEST{
        ll n;
        cin >> n;
        vector<ll> arr(n);
        REP(i,n)
            cin >> arr[i];
        ll o=0,e=0;
        REP(i,n){
            if((i%2)!=(arr[i]%2)){
                if(i&1)
                    o++;
                else
                    e++;
            }
        }
        if(e!=o)
            cout << -1 << endl;
        else
            cout << e << endl;
    }
    return 0;
}