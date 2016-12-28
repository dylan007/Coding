#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a,b;
    cin >> a >> b;
    int i=1;
    while(1)
    {
        if(((a*i-b)%10 == 0) || (a*i)%10 == 0)
            break;
        i++;
    }
    cout << i << endl;
    return 0;
}
