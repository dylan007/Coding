#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void disp(ll n,ll d,ll i)
{
    if(i==((n+1)/2))
    {
        if(n%2 == 0)
            cout << d << " ";
        return;
    }
    cout << d << " ";
    disp(n,(d*(n-i)/(i+1)),i+1);
    cout << d << " ";
    return;
}

int main()
{
    ll n;
    cin >> n;
    for(ll i=0;i<n;i++)
    {
        disp(i,1,0);
        cout << endl;
    }
    return 0;
}
