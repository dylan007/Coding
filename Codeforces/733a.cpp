#include<bits/stdc++.h>

using namespace std;

int main()
{
    string a;
    cin >> a;
    int m=0,curr=1;
    for(int i=0;i<a.length();i++)
    {
        if((a[i]==65)||(a[i]==69)||(a[i]==73)||(a[i]==79)||(a[i]==85)||(a[i]==89))
        {
            m=max(curr,m);
            curr=0;
        }
        curr++;
    }
    cout << m << endl;
    return 0;
}
