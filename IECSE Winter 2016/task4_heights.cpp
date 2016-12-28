#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        ll n,m;
        cin >> n >> m;
        cout << max(n,m)-min(n,m) << endl;
    }
    return 0;
}
