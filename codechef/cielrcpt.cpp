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
        int c=0,i=11;
        while(x)
        {
            c += x/pow(2,i);
            x = x%((int)pow(2,i));
            i--;
        }
        cout << c << endl;
    }
    return 0;
}
