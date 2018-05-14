#include<bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >>T;
    while(T--)
    {
        string a,b;
        cin >> a;
        b=a;
        reverse(a.begin(),a.end());
        if(a!=b)
            cout << "losses" << endl;
        else
            cout << "wins" << endl;
    }
    return 0;
}
