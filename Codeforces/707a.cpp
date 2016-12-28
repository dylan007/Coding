#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    int flag=0;
    getchar();
    for(int i=0;i<n;i++)
    {
        char c;
        for(int j=0;j<m;j++)
        {
            cin >> c;
            if(c=='C' || c=='Y' || c=='M')
                flag=1;
            getchar();
        }
    }
    if(flag) cout << "#Color" << endl;
    else cout << "#Black&White" << endl;
    return 0;
}
