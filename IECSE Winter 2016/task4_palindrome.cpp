#include<bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        string a;
        cin >> a;
        int flag=0,l=a.length();
        for(int i=0;i<(a.length()/2);i++)
        {
            if(a[i]=='.' && a[l-i-1]=='.')
            {
                a[i] = 'a';
                a[l-i-1] = 'a';
            }
            else if(a[l-i-1]=='.')
                a[l-i-1] = a[i];
            else if(a[i]=='.')
                a[i] = a[l-i-1];
            else if(a[i]!=a[l-i-1])
            {
                flag = 1;
                break;
            }
        }
        if(l%2)
            if(a[l/2]=='.') a[l/2]='a';
        if(flag)
            cout << "-1" << endl;
        else
            cout << a << endl;
    }
    return 0;
}
