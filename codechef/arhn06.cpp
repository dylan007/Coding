#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
	long long int T;
	cin >> T;
	unsigned long long int l,r;
	while(T--)
	{
		cin >> l >> r;
		unsigned long long int ans;
		while((l|(l+1)) <= r)
			l = l|(l+1);
		cout << l << endl;
	}
	return 0;
}
