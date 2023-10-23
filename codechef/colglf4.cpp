/*=======================
Author    : Doraemon
File      : colglf4
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

int main()
{
    fast_io;
    TEST
    {
        ll n, e, h, a, b, c;
        cin >> n >> e >> h >> a >> b >> c;
        ll minCost = std::numeric_limits<long long>::max();
        ll f = 0;
        if (min(e, h) == 0)
        {
            if (e == 0)
            {
                if ((h / 3) >= n)
                    cout << b * n << endl;
                else
                    cout << -1 << endl;
            }
            else
            {
                if ((e / 2) >= n)
                    cout << a * n << endl;
                else
                    cout << -1 << endl;
            }
            continue;
        }
        REP(i, n + 1)
        {
            ll cost = 0;
            cost = c * i;
            ll posOm = (e - i) / 2;
            ll posM = (h - i) / 3;
            // error(i, posOm, posM);
            if (min(e, h) < i)
                break;
            if ((i + posOm + posM) >= n)
            {
                ll extra = max((posOm + posM) - (n - i), 0ll);
                if (a < b)
                {
                    if (extra > posM)
                    {
                        posOm -= (extra - posM);
                        posM = 0;
                    }
                    else
                        posM -= extra;
                }
                else
                {
                    if (extra > posOm)
                    {
                        posM -= (extra - posOm);
                        posOm = 0;
                    }
                    else
                        posOm -= extra;
                }
                cost += a * posOm + b * posM;
                // error(i, posOm, posM);
                minCost = min(minCost, cost);
                f = 1;
            }
        }
        if (f)
            cout << minCost << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}