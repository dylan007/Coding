#include<bits/stdc++.h>

using namespace std;

int prime[100001];

void sieve()
{
    memset(prime,0,sizeof(prime));
    prime[1]=1;
    prime[0]=1;
    for(int i=2;i<=100000;i++)
    {
        if(prime[i]==0)
        {
            for(int j=2*i;j<=100000;j+=i)
                prime[j]++;
        }
    }
}

int main()
{
    int T;
    cin >> T;
    sieve();
    while(T--)
    {
        int x;
        cin >> x;
        if(prime[x]==0)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}
