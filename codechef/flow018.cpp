#include<bits/stdc++.h>

using namespace std;

int fact(int n)
{
    return n==0?1:n*fact(n-1);
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        cout << fact(n) << endl;
    }
    return 0;
}
