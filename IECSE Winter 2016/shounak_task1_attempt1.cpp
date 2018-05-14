#include<bits/stdc++.h>
#include<ctime>

using namespace std;
int main()
{
    int start = clock();
    int n,x;
    cin >> n;
    vector<int> a;
    for(int i=0;i<n;i++)
    {
        cin >> x;
        a.push_back(x);
    }
    vector<int> pos;
    cin >> x;
    for(int i=0;i<n;i++)
        if(x==a[i]) pos.push_back(i+1);
    a.erase(remove(a.begin(),a.end(),x),a.end());
    for(int i=0;i<a.size();i++)
        cout << a[i] << " ";
    cout << endl;
    for(int i=0;i<pos.size();i++)
        cout << pos[i] << " ";
    cout << endl;
    int stop = clock();
    cout << "Time : " << (stop-start)/double(CLOCKS_PER_SEC)*1000 << endl;
    return 0;
}
