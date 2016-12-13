#include<bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        int arr[n];
        int x=0;
        for(int i=0;i<n;i++)
        {
            cin >> arr[i];
            x ^= arr[i];
        }
        int c=0;
        for(int i=0;i<n;i++)
            c += ((arr[i]^x) == 0);
        cout << c << endl;
    }
    return 0;
}
