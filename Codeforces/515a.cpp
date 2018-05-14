#include<bits/stdc++.h>

using namespace std;

int main()
{
	int a,b,s;
	cin >> a >> b >> s;
	a = (a<0)?0-a:a;
	b = (b<0)?0-b:b;
	a = a+b;
	if(s >= a)
	{
		if(((s-a)%2 == 0))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	else
		cout << "No\n";
	return 0;
}
