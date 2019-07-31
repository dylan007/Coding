/*=======================
Author    : Shounak Dey
=======================    */

#include<bits/stdc++.h>

using namespace std;

using ll = long long int;
using ull = unsigned long long int;

#define PB push_back
#define MK make_pair
#define SZ(a) (int)(sizeof(a))
#define F first
#define S second
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) for(int i=0;i<n;i++)
#define read(n) scanf("%d",&n)
#define readl(n) scanf("%lld",&n)
#define readul(n) scanf("%llu",&n);


#define SORTV(a) sort(a.begin(),a.end())
#define TEST int Test;cin >> Test;while(Test--)
#define gcd(a,b) __gcd(a,b)
#define ffs(a) __builtin_ffs(a) // find first set
#define clz(a) __builtin_clz(a) // count leading zeroes
#define ctz(a) __builtin_ctz(a) // count trailing zeroes
#define popc(a) __builtin_popcount(a) // count set bits
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)


#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }

vector<string> split(const string& s, char c) {
    vector<string> v;
    stringstream ss(s);
    string x;
    while (getline(ss, x, c))
        v.emplace_back(x);
    return move(v);
}

void err(vector<string>::iterator it) {}
template<typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
    cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << '\n';
    err(++it, args...);
}

int main()
{
    fast_io;
    int n;
    cin >> n;
    priority_queue<int> mxq;
    priority_queue<int,vector<int>,greater<int>> mnq;
    REP(i,n){
        int x;
        cin >> x;
        int l=-1,r=-1;
        if(mnq.size()>0)
            l = mnq.top();
        if(mxq.size()>0)
            r = mxq.top();
        if(x>r)
            mnq.push(x);
        else
            mxq.push(x);
        while(abs((int)mnq.size()-(int)mxq.size())>1){
            if(mnq.size() > mxq.size()){
                int tmp = mnq.top();
                mnq.pop();
                mxq.push(tmp);
            }
            else{
                int tmp = mxq.top();
                mxq.pop();
                mnq.push(tmp);
            }
        }
        cout << setprecision(1) << fixed;
        if(!(i&1)){
            if(mnq.size()>mxq.size())
                cout << (double)mnq.top() << endl;
            else
                cout << (double)mxq.top() << endl;
        }
        else
            cout << ((double)mxq.top() + (double)mnq.top())/2 << endl;
    }
    return 0;
}