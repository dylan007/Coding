/*=======================
Author    : Doraemon
File      : wirel
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

typedef struct LineSegment
{
    pll start;
    pll end;

    LineSegment(pll start, pll end)
    {
        if (start.F > end.S)
        {
            pll temp = end;
            end = start;
            start = temp;
        }
        this->start = start;
        this->end = end;
    }

    LineSegment() {}

    void print()
    {
        cout << "Start: " << start.F << " " << start.S << " End: " << end.F << " " << end.S << endl;
    }

} LineSegment;

#define mX 1000000

pll negP1 = {mX + 1, mX};
pll negP2 = {mX, mX + 1};

pll shift(pll origin, pll point)
{
    pll s = {0, 0};
    s.F = origin.F - point.F;
    s.S = origin.S - point.S;
    return s;
}

int main()
{
    fast_io;
    ll n, m;
    cin >> n >> m;
    vector<pll> points;
    REP(i, n)
    {
        ll x, y;
        cin >> x >> y;
        points.PB(MK(x, y));
    }
    vector<LineSegment> ls;
    REP(i, n)
    {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ls.PB(LineSegment(MK(a, b), MK(c, d)));
    }
    cout << -1 - ls[0].start.F << " " << 0 - ls[0].start.S << endl;
    pll negShift = shift(ls[1].start, negP1);
    cout << negShift.F << " " << negShift.S << endl;
    REP(i, m - 2)
    {
        cout << 0 << " " << 0 << endl;
    }
}