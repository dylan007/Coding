#include<bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        double x,y;
        cin >> x >> y;
        cout << sqrt(y*y - x*x) << " " << sqrt(y*y + x*x) << endl;
    }
    return 0;
}
