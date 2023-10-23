/*=======================
Author    : Shounak Dey
File      : d
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

int main()
{
    fast_io;
    ll h, w;
    cin >> h >> w;
    pll start;
    cin >> start.F >> start.S;
    ll n;
    cin >> n;
    map<ll, vector<ll>> row, col;
    REP(i, n)
    {
        pll wall;
        cin >> wall.F >> wall.S;
        if (row.find(wall.F) == row.end())
            row[wall.F] = vector<ll>();
        if (col.find(wall.S) == col.end())
            col[wall.S] = vector<ll>();
        row[wall.F].PB(wall.S);
        col[wall.S].PB(wall.F);
    }
    for (auto &it : row)
        sort(it.S.begin(), it.S.end());
    for (auto &it : col)
        sort(it.S.begin(), it.S.end());
    // for (auto it : col)
    // {
    //     for (auto iter : it.S)
    //         cout << iter << " ";
    //     cout << endl;
    // }

    string vertical = "UD";
    ll q;
    cin >> q;
    pll pos = start;
    while (q--)
    {
        pair<char, ll> inst;
        cin >> inst.F >> inst.S;
        if (vertical.find(inst.F) != string::npos)
        {
            if (col.find(pos.S) != col.end())
            {

                // cout << "COL:";
                // for (auto it : col[pos.S])
                //     cout << it << " ";
                // cout << endl;
                vector<ll>::iterator it = upper_bound(col[pos.S].begin(), col[pos.S].end(), pos.F);
                // cout << "VAL:" << *it << endl;
                if (inst.F == 'U')
                {
                    if (it == col[pos.S].begin())
                        pos.F -= inst.S;
                    else
                    {
                        it--;
                        pos.F = max(pos.F - inst.S, (*it) + 1);
                    }
                }
                else
                {
                    if (it == col[pos.S].end())
                        pos.F += inst.S;
                    else
                    {
                        pos.F = min(pos.F + inst.S, (*it) - 1);
                    }
                }
            }
            else
                pos.F += (inst.F == 'U' ? -1 : 1) * inst.S;
        }
        else
        {
            if (row.find(pos.F) != row.end())
            {
                // cout << "ROW:";
                // for (auto it : col[pos.S])
                //     cout << it << " ";
                // cout << endl;
                vector<ll>::iterator it = upper_bound(row[pos.F].begin(), row[pos.F].end(), pos.S);
                // cout << (*it) << endl;
                if (inst.F == 'L')
                {
                    if (it == row[pos.F].begin())
                        pos.S -= inst.S;
                    else
                    {
                        it--;
                        pos.S = max(pos.S - inst.S, (*it) + 1);
                    }
                }
                else
                {
                    if (it == row[pos.F].end())
                        pos.S += inst.S;
                    else
                    {
                        pos.S = min(pos.S + inst.S, (*it) - 1);
                    }
                }
            }
            else
                pos.S += (inst.F == 'L' ? -1 : 1) * inst.S;
        }
        pos.F = min(h, max(pos.F, 1ll));
        pos.S = min(w, max(pos.S, 1ll));
        cout << pos.F << " " << pos.S << endl;
    }
    return 0;
}