#include<bits/stdc++.h>

using namespace std;

int main()
{
	char inp[20],c;
	cin >> inp;
	for(int i=0;i<strlen(inp);i++)
	{
		if(i==0 && inp[i]=='9')
			cout << inp[i];
		else if(inp[i]>='5' && inp[i]<='9')
		{
			c = '0'+'9'-inp[i];
			cout << c;
		}
		else
			cout << inp[i];
	}
	cout << endl;
	return 0;
}
