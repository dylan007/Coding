/*=======================
Author    : Shounak Dey
File      : 1573c
=======================*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long int;
using ull = unsigned long long int;

#define PB push_back
#define MK make_pair
#define SZ(a) (int)(sizeof(a))
#define F first
#define S second
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define REP(i, n) for (int i = 0; i < n; i++)
#define read(n) scanf("%d", &n)
#define readl(n) scanf("%lld", &n)
#define readul(n) scanf("%llu", &n);

#define SORTV(a) sort(a.begin(), a.end())
#define TEST     \
    int Test;    \
    cin >> Test; \
    while (Test--)
#define gcd(a, b) __gcd(a, b)
#define ffs(a) __builtin_ffs(a)       // find first set
#define clz(a) __builtin_clz(a)       // count leading zeroes
#define ctz(a) __builtin_ctz(a)       // count trailing zeroes
#define popc(a) __builtin_popcount(a) // count set bits
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define error(args...)                         \
    {                                          \
        vector<string> _v = split(#args, ','); \
        err(_v.begin(), args);                 \
    }

vector<string> split(const string &s, char c)
{
    vector<string> v;
    stringstream ss(s);
    string x;
    while (getline(ss, x, c))
        v.emplace_back(x);
    return move(v);
}
void err(vector<string>::iterator it) {}
template <typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args)
{
    cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n';
    err(++it, args...);
}

using pll = pair<ll, ll>;

vector<vector<ll>> adj;
vector<ll> color;
vector<ll> res;
vector<ll> v;

void dfs2(ll x)
{
    v[x] = 1;
    if (adj[x].size() == 0)
        res[x] = 1;
    for (auto it : adj[x])
    {
        if (v[it] == 0)
            dfs2(it);
        res[x] = max(res[x], res[it] + (it > x));
    }
}

bool dfs(ll x)
{
    color[x] = 1;
    for (auto it : adj[x])
    {
        if (color[it] == 1)
            return true;
        if ((color[it] == 0) && dfs(it))
            return true;
    }
    color[x] = 2;
    return false;
}

ll check_cycle(ll n)
{
    color = vector<ll>(n, 0);
    bool isCyclic = false;
    REP(i, n)
    {
        if (color[i] == 0)
            isCyclic |= dfs(i);
    }
    return isCyclic;
}

int main()
{
    fast_io;
    TEST
    {
        ll n;
        cin >> n;
        adj = vector<vector<ll>>(n, vector<ll>());
        vector<ll> inDeg = vector<ll>(n, 0);
        color = vector<ll>(n, 0);
        res = vector<ll>(n, 0);
        v = vector<ll>(n, 0);
        REP(i, n)
        {
            ll c;
            cin >> c;
            inDeg[i] = c;
            while (c--)
            {
                ll x;
                cin >> x;
                x--;
                adj[i].PB(x);
            }
        }
        ll f = check_cycle(n);

        if (f)
        {
            cout << -1 << endl;
            continue;
        }
        else
        {
            ll out = 0;
            REP(i, n)
            {
                if (v[i] == 0)
                    dfs2(i);
                out = max(out, res[i]);
            }
            cout << out << endl;
        }
    }
    return 0;
}