#include<bits/stdc++.h>

using namespace std;

int main()
{
    double y,x,sum=0,c=0;
    for(int i=0;i<9;i++)
    {
        cin >> x >> y;
        sum += x*y;
        c += x;
    }
    cout << sum/c << endl;
    return 0;
}
