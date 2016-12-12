#include<bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        string a;
        cin >> a;
        cout << int(a[0])+int(a[a.length()-1])-2*int('0') << endl;
    }
    return 0;
}
