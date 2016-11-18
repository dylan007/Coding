#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string a;
    cin >> a;
    int c1=0,c2=0;
    for(int i=0;i<a.length();i++)
        a[i]=='A'?c1++:c2++;
    if(c1>c2)
        cout << "Anton" << endl;
    else if(c2>c1)
        cout << "Danik" << endl;
    else
        cout << "Friendship" << endl;
    return 0;
}
