#include<iostream>
#include<bits/stdc++.h>

using namespace std;

unsigned long long int fib[1000001];

long long int gcd(long long int a,long long int b)
{
	return (b!=0)?gcd(b,a%b):a;
}

void sieve()
{
	int i=2;
	for(i=2;i<=1000000;i++)
		fib[i]=(fib[i-1]+fib[i-2])%1000000007;
}

int main()
{
	int T;
	cin >> T;
	fib[0]=0;
	fib[1]=1;
	sieve();
	cout << endl;
	while(T--)
	{
		long long int a,b,ans;
		cin >> a >> b;
		ans = gcd(a,b);
		cout << fib[ans]%1000000007 << endl;
	}
	return 0;
}
