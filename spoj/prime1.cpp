#include<bits/stdc++.h>

using namespace std;

int prime[1000000000]={0};

void sieve()
{
	for(int i=2;i<100000;i++)
	{
		if(prime[i]==0)
		{
			cout << i << endl;
			for(int j=2*i;j<1000000000;j+=i)
				prime[j]=1;
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
		int m,n;
		cin >> m >> n;
		for(int i=m;i<=n;i++)
		{
			if(prime[i]==1)
				cout << i << endl; 
		}
	}
	return 0;
}
