#include<bits/stdc++.h>
#include<string>

using namespace std;

int primes[111]={0};

void sieve()
{
    primes[0]=1;
    primes[1]=1;
    for(int i=2;i<=110;i++)
    {
        if(primes[i]==0)
        {
            for(int j=2*i;j<=110;j+=i)
                primes[j]=1;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    sieve();
    int flag=0;
    if(primes[n]==0)
    {
        if(n/10 == 0)
            cout << "1" << n << endl;
        else
            cout << "-1" << endl;
    }
    else
    {
        int i=2;
        string a="";
        while(n/10)
        {
            if(i>=10)
            {
                if(n>1)
                    flag=1;
                break;
            }
            if(primes[i]==1)
            {
                i++;
                continue;
            }
            string x;
            stringstream ss;
            ss << i;
            x = ss.str();
            while(n%i == 0)
            {
                if(n<10)
                    break;
                a += x;
                n /= i;
            }
            i++;
        }
        string x;
        stringstream ss;
        ss << n;
        x = ss.str();
        a += x;
        if(flag)
            cout << "-1" << endl;
        else
            cout << a << endl;
    }
    cout << endl;
    return 0;
}
