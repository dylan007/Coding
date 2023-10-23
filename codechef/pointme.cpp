/*=======================
Author    : Doraemon
File      : pointme
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

ll calc(ll dx, ll dy)
{
    if (abs(dx) == abs(dy))
        return 1;
    if (dy == 0)
        return 1;
    if (dx == 0)
        return 1;
    return 2;
}

int main()
{
    fast_io;
    TEST
    {
        ll n;
        cin >> n;
        vector<ll> x(n), y(n);
        REP(i, n)
        cin >> x[i];
        REP(i, n)
        cin >> y[i];

        ll out = LONG_MAX;
        REP(i, n)
        {
            ll ans = 0;
            REP(j, n)
            {
                if (i == j)
                    continue;
                ans += calc(x[i] - x[j], y[i] - y[j]);
            }
            out = min(out, ans);
        }
        cout << out << endl;
    }
    return 0;
}