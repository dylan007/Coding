#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,c;
    cin >> n >> c;
    int x,y,ans=1;
    cin >> x;
    y = x;
    for(int i=2;i<=n;i++)
    {
        cin >> x;
        if(x-y > c)
        {
            ans = 1;
            y = x;
            continue;
        }
        ans++;
        y=x;
    }
    cout << ans  << endl;
    return 0;
}
