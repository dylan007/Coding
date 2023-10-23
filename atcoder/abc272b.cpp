/*=======================
Author    : Shounak Dey
File      : abc272b
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
    int n, m;
    cin >> n >> m;
    vector<unordered_set<int>> parties = vector<unordered_set<int>>(n);
    REP(i, m)
    {
        int k;
        int x;
        cin >> k;
        while (k--)
        {
            cin >> x;
            parties[x - 1].insert(i);
        }
    }
    bool out = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            bool hasCommon = false;
            for (int k = 0; k < m; k++)
            {
                if (parties[i].find(k) != parties[i].end())
                {
                    if (parties[j].find(k) != parties[j].end())
                        hasCommon = true;
                }
            }
            if (hasCommon == false)
            {
                out = false;
                break;
            }
        }
        if (out == false)
            break;
    }
    cout << (out ? "Yes" : "No") << endl;
    return 0;
}