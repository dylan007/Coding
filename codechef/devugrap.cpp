#include<bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int a,b;
        int c=0;
        cin >> a >> b;
        int x;
        while(a--)
        {
            cin >> x;
            c += min(x%b,b-x%b);
        }
        cout << c << endl;
    }
    return 0;
}
