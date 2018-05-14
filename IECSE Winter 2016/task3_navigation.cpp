#include<bits/stdc++.h>

using namespace std;

int main()
{
    string a;
    cin >> a;
    int c=0;
    for(int i=0;i<a.length();i++)
    {
        if(a[i]=='U' || a[i]=='R')
            c++;
        else
            c--;
    }
    if(a.length()%2 == 0)
        cout << abs(c)/2 << endl;
    else
        cout << "-1" << endl;
    return 0;
}
