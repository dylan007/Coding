#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int fib(int n)
{
	if(n==0)
		return 2;
	else if(n==1)
		return 5;
	else
		return (2*fib(n-1)+3*fib(n-2))%1000000007;
}

int main()
{
	int T;
	cin >> T;
	int x;
	for(int i=0;i<T;i++)
	{
		cin >> x;
		cout << fib(x) << endl;
	}
	return 0;
}
