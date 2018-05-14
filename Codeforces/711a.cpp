#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	string a[n];
	int flag=-1;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		if((a[i][0]==a[i][1])&&(a[i][0] == 'O'))
			flag=2*i;
		else if((a[i][3]==a[i][4]) && (a[i][3]=='O'))
			flag=2*i+1;
	}
	if(flag>=0)
	{
		if(flag%2 == 0)
		{
			flag = flag/2;
			//zerodol,sp
			a[flag][0] = '+';
			a[flag][1] = '+';
		}
		else
		{
			flag = flag/2;
			a[flag][3] = '+';
			a[flag][4] = '+';
		}
	}
	if(flag>=0)
	{
		cout << "YES" << endl;
		for(int i=0;i<n;i++)
			cout << a[i] << endl;
	}
	else
		cout << "NO" << endl;
	return 0;

}
