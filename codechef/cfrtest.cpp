#include<bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n,x;
        cin >> n;
        vector<int> a;
        while(n--)
        {
            cin >> x;
            if(find(a.begin(),a.end(),x)==a.end())
                a.push_back(x);
        }
        cout << a.size() << endl;
    }
    return 0;
}
