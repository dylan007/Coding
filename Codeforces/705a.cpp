#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string a="I hate",b="I love";
    for(int i=1;i<n;i++)
    {
        if(i%2 == 1)
            cout << a;
        else
            cout << b;
        cout << " that ";
    }
    if(n%2 == 1)
        cout << a;
    else
        cout << b;
    cout << " it" << endl;
    return 0;
}
