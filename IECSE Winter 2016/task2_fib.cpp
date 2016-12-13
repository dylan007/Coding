#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll fib[50];

ll totient(ll x)
{
    double phi = (sqrt(5)+1)/2;
    return floor(log(x*sqrt(5) + 0.5)/log(phi));
}

ll gen_fib(ll x)
{
    if(fib[x]==-1)
    {
        fib[x] = gen_fib(x-1)+gen_fib(x-2);
        return fib[x];
    }
    return fib[x];
}

int main()
{
    memset(fib,-1,50*sizeof(ll));
    fib[0]=1;
    fib[1]=1;
    ll n,x=1,y;
    cin >> n;
    ll i=0;
    n = totient(n);
    //cout << n << endl;
    gen_fib(n);
    for(int i=0;i<n;i++)
        cout << fib[i] << " ";
    cout << endl;
    cout << endl;
    return 0;
}
