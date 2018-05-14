#include<bits/stdc++.h>

using namespace std;

int main()
{
	string a,b;
	cin >> a >> b;
	int flag=0;
	for(int i=0;i<a.length();i++)
	{
		if(a[i]<b[i])
			flag = 1;
	}
	if(flag)
		cout << "-1" << endl;
	else
		cout << b <<endl;
	return 0;
}

