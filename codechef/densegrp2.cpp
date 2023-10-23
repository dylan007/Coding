/*=======================
Author    : Doraemon
File      : densegrp2
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

// Define structs
typedef struct Range
{
    ll start;
    ll end;
    ll index;

    Range(ll start, ll end, ll index)
    {
        this->start = start;
        this->end = end;
        this->index = index;
    }

    Range() {}

    void print()
    {
        cout << "Range: " << start << " " << end << "\tID:" << index << endl;
    }
} Range;

typedef struct Node
{
    ll l;
    ll r;
    set<ll> indexSet;

    Node(ll l, ll r)
    {
        this->l = l;
        this->r = r;
        this->indexSet = set<ll>();
    }

    Node() {}

    void print()
    {
        cout << "Range  : " << l << " " << r;
        cout << "Indices: ";
        for (auto it : indexSet)
            cout << it << " ";
        cout << endl;
    }
} Node;

//define variables
ll n, m, x, y;
vector<Range> ranges;
vector<ll> endPoints;
//functions
void input()
{
    cin >> n >> m >> x >> y;
    ranges = vector<Range>(2 * m);
    REP(i, m)
    {
        ll ax, ay, bx, by;
        cin >> ax >> ay >> bx >> by;
        ranges[i] = Range(ax, ay, i);
        ranges[i + m] = Range(bx, by, i + m);
    }
    REP(i, 2 * m)
    ranges[i].print();
}

void build_seg_tree()
{
}

void preprocess()
{
    // build elemetary points
    unordered_set<ll> s;
    REP(i, 2 * m)
    {
        if (s.find(ranges[i].start) == s.end())
            endPoints.PB(ranges[i].start);
        s.insert(ranges[i].start);
        if (s.find(ranges[i].end) == s.end())
            endPoints.PB(ranges[i].end);
        s.insert(ranges[i].end);
    }
    SORTV(endPoints);
    for (auto it : endPoints)
        cout << it << " ";
    cout << endl;

    // build elementary ranges
}

void solve()
{
}

int main()
{
    fast_io;
    TEST
    {
        input();
        preprocess();
        solve();
    }
    return 0;
}