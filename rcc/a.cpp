#include<bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int x;
		cin >> x;
		string out="";
		while(x)
		{
			string a=" ";
			a[0] = "A"+(x%26);
			out = a+out;
		}
		cout << out << endl;
	}	
	return 0;
}

