#include<bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        string a;
        cin >> a;
        if(a.find("I") != std::string::npos)
            cout << "INDIAN" << endl;
        else if(a.find("Y") != std::string::npos)
            cout << "NOT INDIAN" << endl;
        else
            cout << "NOT SURE" << endl;
    }
    return 0;
}
