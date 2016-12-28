#include<bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n,k;
        cin >> n >> k;
        int votes[n];
        memset(votes,0,sizeof(votes));
        int x;
        for(int i=0;i<n;i++)
        {
            cin >> x;
            if(x==(i+1))
                votes[x-1] = INT_MIN;
            else
                votes[x-1]++;
        }
        int c=0;
        for(int i=0;i<n;i++) c += (votes[i]>=k);
        cout << c << endl;
    }
    return 0;
}
