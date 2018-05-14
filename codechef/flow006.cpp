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
        int count=0;
        for(int i=0;i<a.length();i++)
            count += (int)a[i];
        count -= a.length()*'0';
        cout << count << endl;
    }
    return 0;
}
