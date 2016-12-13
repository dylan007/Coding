#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int x,c1=0,c2=0;
    while(n--)
    {
        cin >> x;
        c1 += x%2;
        c2 += !(x%2);
    }
    if(c2>c1)
        cout << "READY FOR BATTLE" << endl;
    else
        cout << "NOT READY" << endl;
    return 0;
}
