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
        int c[26]={0};
        for(int i=0;i<a.length();i++)
            c[a[i]-'a']++;
        int flag=0;
        for(int i=0;i<26;i++)
            flag |= (c[i]==(a.length()/2));
        flag &= (a.length()%2 == 0);
        if(flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
