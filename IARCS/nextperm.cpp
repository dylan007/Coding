#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    while(k--)
    {
        int arr[n];
        for(int i=0;i<n;i++)
            cin >> arr[i];
        int k,l;
        for(int i=(n-2);i>0;i--)
        {
            if(arr[i]>arr[i+1])
            {
                k=i;
                break;
            }
        }
        for(int i=(n-1);i>k;i++)
        {
            if(arr[i]>arr[k])
            {
                l=i;
                break;
            }
        }
        arr[k] = arr[l]+arr[k];
        arr[l] = arr[k]-arr[l];
        arr[k] -= arr[l];
        for(int i=(k+1);i<=((n+k)/2);i++)
        {
            arr[i] += arr[n-i-1];
            arr[n-i-1] = arr[i] - arr[n-i-1];
            arr[i] -= arr[n-i-1];
        }
        for(int i=0;i<n;i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
