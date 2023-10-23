/*=======================
Author    : Shounak Dey
File      : abc272c
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
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    REP(i, n)
    cin >> arr[i];
    sort(arr.begin(), arr.end(), [](const int a, const int b)
         {
        bool pa = a&1;
        bool pb = b&1;
        if(pa==pb){
            return a<b;
        }
        return pa; });
    int ind = -1;
    REP(i, n)
    {
        if (!(arr[i] & 1))
        {
            ind = i;
            break;
        }
    }
    // for (auto it : arr)
    //     cout << it << " ";
    // cout << endl;
    int out = -1;
    if (ind >= 2)
        out = arr[ind - 1] + arr[ind - 2];
    if ((n - 1 - ind) >= 1)
        out = max(out, arr[n - 1] + arr[n - 2]);
    cout << out << endl;
    return 0;
}