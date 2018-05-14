#include<bits/stdc++.h>

using namespace std;

int main()
{
    string a,b;
    cin >> a >> b;
    int flag=0;
    for(int i=0;i<a.length();i++)
    {
        if(a[i]=='0')
        {
            if(b[i]=='1')
            {
                flag=1;
                break;
            }
        }
    }
    if(flag)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    return 0;
}
