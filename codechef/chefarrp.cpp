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
        int x,sum[n],prod[n];
        memset(sum,0,sizeof(sum));
        memset(prod,1,sizeof(sum));
        cin >> x;
        sum[0]=x;
        prod[0] = x;
        for(int i=1;i<n;i++)
        {
            cin >> x;
            sum[i] = sum[i-1]+x;
            prod[i] = prod[i-1]*x;
        }
        int c=0,s,p;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                s = sum[j]-(i==0?0:sum[i-1]);
                p = prod[j]/(i==0?1:prod[i-1]);
                //cout << s << " " << p << " " << i << " " << j << endl;
                c += s==p;
            }
        }
        cout << c << endl;
    }
    return 0;
}
