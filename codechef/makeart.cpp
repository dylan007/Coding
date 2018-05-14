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
        int flag=0;
        for(int i=0;i<n;i++) cin >> arr[i];
        for(int i=0;i<(n-2);i++)
        {
            if(arr[i]==arr[i+1] && arr[i]==arr[i+2])
                flag=1;
        }
        if(flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
