/*=======================
Author    : Doraemon
File      : mndigsumsmall
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

ll dis(ll x, ll b, ll curr)
{
    ll ret = 0;
    while (x)
    {
        ret += (x % b);
        x /= b;
        if (ret > curr)
            return curr + 1;
    }
    return ret;
}

bool check(ll x)
{
    if (x == 1)
        return true;

    for (int i = 2; (i * i) <= x; i++)
    {
        double v = log(x) / log(i);
        if ((v - (int)v) < 0.00001)
            return true;
    }
    return false;
}

int main()
{
    fast_io;
    TEST
    {
        ll n, l, r;
        cin >> n >> l >> r;
        r = min(r, n);
        if (l > n)
            cout << l << endl;
        else if (l >= (n / 2 + 1))
            cout << r << endl;
        else
        {
            ll minVal = 2;
            if (check(n))
                minVal = 1;
            ll out = LONG_MAX;
            ll m = LONG_MAX;
            FOR(i, l, r + 1)
            {
                ll p = dis(n, i, m);
                if (p < m)
                {
                    m = p;
                    out = i;
                }
                if (m == minVal)
                    break;
            }
            cout << out << endl;
        }
    }
    return 0;
}