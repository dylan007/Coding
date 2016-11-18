#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int sum=0,x;
    x = min(a,min(c,d));
    sum += 256*(min(a,min(c,d)));
    a -= x;
    c -= x;
    d -= x;
    sum += 32*(min(a,b));
    cout << sum << endl;
    return 0;
}
