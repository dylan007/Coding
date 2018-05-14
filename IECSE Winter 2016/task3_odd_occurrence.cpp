#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,x,ans=0;
    cin >> n;
    while(n--)
    {
        cin >> x;
        ans ^= x;
    }
    cout << ans << endl;
    return 0;
}
