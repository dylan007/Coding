#include<bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n,m,k;
        cin >> n >> m >> k;
        int visited[n];
        int x;
        memset(visited,0,n*sizeof(int));
        for(int i=0;i<m;i++)
        {
            cin >> x;
            visited[x-1]++;
        }
        for(int i=0;i<k;i++)
        {
            cin >> x;
            visited[x-1]++;
        }
        //for(int i=0;i<n;i++)
          //  cout << visited[i] << " ";
        //cout << endl;
        int count=0;
        for(int i=0;i<n;i++)
            count += (visited[i]==2);
        cout << count << " ";
        count=0;
        for(int i=0;i<n;i++)
            count += (visited[i]==0);
        cout << count << endl;
    }
    return 0;
}
