#include<bits/stdc++.h>

using namespace std;

int f(string a)
{
    int bal=0,m_bal=0;
    for(int i=0;i<a.length();i++)
    {
        bal += (a[i]=='(');
        bal -= (a[i]==')');
        m_bal = max(bal,m_bal);
    }
    return m_bal;
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        string a;
        cin >> a;
        int x;
        x = f(a);
        for(int i=0;i<x;i++)
            cout << "(";
        for(int i=0;i<x;i++)
            cout << ")";
        cout << endl;
    }
    return 0;
}
