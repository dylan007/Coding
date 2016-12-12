#include<bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    int denoms[6] = {100,50,10,5,2,1};
    while(T--)
    {
        int x;
        cin >> x;
        int i=0,c=0;
        while(x)
        {
            c += x/denoms[i];
            x %= denoms[i];
            i++;
        }
        cout << c << endl;
    }
    return 0;
}
