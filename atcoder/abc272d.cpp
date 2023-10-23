/*=======================
Author    : Shounak Dey
File      : abc272d
=======================*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long int;
using ull = unsigned long long int;
using pll = pair<ll, ll>;

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

ll dist(ll x1, ll y1, ll x2, ll y2)
{
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main()
{
    fast_io;
    int n, m;
    cin >> n >> m;
    queue<pll> q;
    vector<vector<vector<pll>>> adj = vector<vector<vector<pll>>>(n, vector<vector<pll>>(n, vector<pll>()));
    REP(i, n)
    {
        REP(j, n)
        {
            REP(k, n)
            {
                REP(l, n)
                {
                    error(i, j, k, l);
                    if (dist(i, j, k, l) == m)
                        adj[i][j].PB(MK(k, l));
                }
            }
        }
    }
    cout << "built" << endl;

    q.push(MK(0l, 0l));
    vector<vector<int>> visited(n, vector<int>(n, -1));
    visited[0][0] = 0;
    while (!q.empty())
    {
        pll curr = q.front();
        q.pop();
        ll level = visited[curr.first][curr.second];
        for (auto it : adj[curr.first][curr.second])
        {
            if (visited[it.first][it.second] == -1)
            {
                visited[it.first][it.second] = level + 1;
                q.push(MK(it.first, it.second));
            }
        }
    }
    REP(i, n)
    {
        REP(j, n)
        cout << visited[i][j] << " ";
        cout << endl;
    }
    return 0;
}