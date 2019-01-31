/*=======================
Author    : Shounak Dey
=======================	*/

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

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> &a,bool inv){
    ll n = a.size();
    if(n==1)
        return;
    vector<cd> a0(n/2),a1(n/2);
    for(ll i=0;2*i < n;i++){
        a0[i] = a[2*i];
        a1[i] = a[2*i + 1];
    }
    fft(a0,inv);
    fft(a1,inv);
    double ang = 2 * PI / n * (inv?-1:1);
    cd w(1),wn(cos(ang),sin(ang));
    for(ll i=0;2*i < n;i++){
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        if(inv){
            a[i] /= 2;
            a[i + n/2] /= 2;
        }
        w *= wn;
    }
}

int main()
{
	fast_io;
    TEST{
        ll n,N;
        cin >> n;
        N = n;
        vector<ll> a(n+1),b(n+1);
        REP(i,n+1)
            cin >> a[i];
        REP(i,n+1)
            cin >> b[i];
        ll tmp = 1;
        while(tmp < (a.size() + b.size()))
            tmp <<= 1;
        n = tmp;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        a.resize(n);
        b.resize(n);
        //error(n);
        vector<cd> pa(a.begin(),a.end()),pb(b.begin(),b.end());
        fft(pa,false);
        fft(pb,false);
        REP(i,n)
            pa[i] *= pb[i];
        fft(pa,true);
        vector<ll> result(n);
        REP(i,n)
            result[i] = round(pa[i].real());
        ll pos = 2*N;
        while(pos>=0)
            cout << result[pos--] << " ";
        cout << endl;
    }
	return 0;
}

