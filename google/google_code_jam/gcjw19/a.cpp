/*=======================
Author    : Shounak Dey
=======================*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
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
#define TEST int Test;cin >> Test;while(Test--):
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
    int T;
    cin >> T;
    for(int test=1;test<=T;test++){
        cout << "Case #" << test << ": ";
        int r,c,k;
        cin >> r >> c >> k;
        string tmp = "";
        for(int i=0;i<c;i++) 
            tmp += "S";
        vector<string> doors(r,tmp);
        int dir=1,x=0,y=0,p=0;
        while(p<k){
            if(dir==1)
                doors[x][y] = 'W';
            else
                doors[x][y] = 'E';
            if((y==(c-1) && dir==1) || (y==0 && dir==-1)){
                x++;
                dir = (dir==1)?-1:1;
            }
            else{
                if((y==0 && dir==1) || (y==(c-1) && dir==-1))
                    doors[x][y] = 'N';
                y += dir;
            }
            p++;
            // error(x,y,p,dir);
        }
        int count = c;
        if((k/c)>=(r-1))
            p = r*c-p;
        else
            p = c;
        error(p);
        if(p==1 && c!=1)
            cout << "IMPOSSIBLE" << endl;
        else{
            if(p>0){
                x = r-1;
                y = 0;
                doors[x][y] = 'N';
                p--;
                y++;
                while(p--){
                    doors[x][y] = 'W';
                    y++;
                }
            }
            cout << "POSSIBLE" << endl;
            for(auto it:doors)
                cout << it << endl;
        }
    }
    return 0;
}