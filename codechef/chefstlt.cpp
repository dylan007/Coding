#include<bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        string a,b;
        cin >> a >> b;
        int c1=0,c2=0,c=0;
        for(int i=0;i<a.length();i++)
        {
            c1 += (a[i]=='?' || b[i]=='?');
            c += (a[i]!=b[i] && a[i]!='?' && b[i]!='?');
        }
        cout << c << " " << c+c1 << endl;
    }
    return 0;
}
