#include<bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        if(a==0 || b==0 || c==0 || (a+b+c)!=180)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}
