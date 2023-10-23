/*=======================
Author    : Shounak Dey
File      : moons
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
    ll T;
    cin >> T;
    REP(t, T)
    {
        ll x, y;
        cin >> x >> y;
        string art;
        cin >> art;
        ll n = art.length();
        ll dp[n + 1][2] = {0};

        if (art[0] == 'C')
            dp[0][1] = INT_MAX;
        else if (art[0] == 'J')
            dp[0][0] = INT_MAX;

        for (int i = 1; i < n; i++)
        {
            if (art[i] == 'C')
            {
                //JC
                dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + y);
                dp[i][1] = INT_MAX;
            }
            else if (art[i] == 'J')
            {
                //CJ
                dp[i][1] = min(dp[i - 1][1], dp[i - 1][0] + x);
                dp[i][0] = INT_MAX;
            }
            else
            {
                //C? or J?
                dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + y);
                dp[i][1] = min(dp[i - 1][1], dp[i - 1][0] + x);
            }
        }
        cout << "Case #" << t + 1 << ": " << min(dp[n - 1][0], dp[n - 1][1]) << endl;
    }
    return 0;
}