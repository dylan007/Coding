#include<bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int x;
        cin >> x;
        x = ((x/2)*(x/2 - 1))/2;
        cout << x << endl;
    }
    return 0;
}
