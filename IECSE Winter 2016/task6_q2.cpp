#include<bits/stdc++.h>

using namespace std;

struct sort_pred{
    bool operator()(const pair<string,pair<string,int> > &left,const pair<string,pair<string,int> > &right) {
        if(left.second == right.second)
            return left.first < right.first;
        return left.second < right.second;
    }
};

int main()
{
    int n;
    cin >> n;
    vector< pair<string,pair<string,int> > > a;
    pair<string,pair<string,int> > temp;
    pair<string,int> TEMP;
    for(int i=0;i<n;i++)
    {
        string x,y;
        cin >> x >> y;
        y[0] = (y[0]=='B')?'C':y[0];
        TEMP = make_pair(y,i);
        temp = make_pair(x,TEMP);
        a.push_back(temp);
    }
    sort(a.begin(),a.end(),sort_pred());
    for(int i=0;i<n;i++)
        cout << a[i].first << endl;
    return 0;
}
