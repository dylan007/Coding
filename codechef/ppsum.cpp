#include<bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n,d;
        cin >> d >> n;
        while(d--)
            n = n*(n+1)/2;
        cout << n << endl;
    }
    return 0;
}
