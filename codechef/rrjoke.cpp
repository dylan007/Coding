#include<bits/stdc++.h>

using namespace std;


int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int x,ans=1;
        cin >> x;
        int a,b;
        for(int i=0;i<x;i++)
            cin >> a >> b;
        for(int i=2;i<=x;i++)
            ans ^= i;
        cout << ans << endl;
    }
    return 0;
}
