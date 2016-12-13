#include<bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >>T;
    while(T--)
    {
        double a,b,c;
        cin >> a >> b >> c;
        a = a>50;
        b = b<0.7;
        c = c>5600;
        int score=0;
        if(a&&b&&c)
            score = 10;
        else if(a&&b&&!c)
            score = 9;
        else if(!a&&b&&c)
            score = 8;
        else if(a&&!b&&c)
            score = 7;
        else if(a||b||c)
            score = 6;
        else
            score = 5;
        cout << score << endl;
    }
    return 0;
}
