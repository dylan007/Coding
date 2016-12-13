#include<bits/stdc++.h>
#include<ctime>

using namespace std;

int main()
{
    int start = clock();
    int n,x;
    cin >> n;
    map < int,vector<int> > a;
    vector<int> nums;
    for(int i=0;i<n;i++)
    {
        cin >> x;
        nums.push_back(x);
        if(a.find(x)==a.end())
        {
            vector<int> temp;
            temp.push_back(i+1);
            a.insert(make_pair(x,temp));
        }
        else
            a[x].push_back(i+1);
    }
    cin >> x;
    for(int i=0;i<n;i++)
        if(nums[i]!=x) cout << nums[i] << " ";
    cout << endl;
    typedef map< int,vector<int> >::iterator it;
    if(a.find(x)==a.end())
        cout << "Number does not exist in the list" << endl;
    else
    {
        vector<int> temp;
        temp = a[x];
        for(int i=0;i<temp.size();i++)
            cout << temp[i] << " ";
        cout << endl;
    }
    /*for(it iterator=a.begin();iterator != a.end();iterator++)
    {
        cout << iterator->first << endl;
        vector<int> temp = iterator->second;
        for(int i=0;i<temp.size();i++)
            cout << temp[i] << " ";
        cout<< endl;
    }*/
    int stop = clock();
    cout << "Time : " << (stop-start)/double(CLOCKS_PER_SEC)*1000 << endl;
    return 0;
}
