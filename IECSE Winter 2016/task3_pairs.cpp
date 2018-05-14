#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >>n;
    map < int,int > counts;
    int x;
    for(int i=0;i<n;i++)
    {
        cin >> x;
        if(counts.find(x)==counts.end())
            counts.insert(make_pair(x,1));
        else
            counts[x]++;
    }
    typedef map<int,int>::iterator it_type;
    int c=0;
    for(it_type it=counts.begin();it!=counts.end();it++)
        c += (it->second)/2;
    cout << c << endl;
    return 0;
}
