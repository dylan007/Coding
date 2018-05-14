#include<bits/stdc++.h>

using namespace std;

int main()
{
	string a;
	cin >> a;
	int count[26] = {0};
	int m = 0;
	for(int i=0;i<a.length();i++)
		count[int(a[i])-int('a')]++;
	int i;
	for(i=25;i>=0;i--)
	{
		if(count[i])
			break;
	}
	m = count[i];
	for(int j=0;j<m;j++)
		printf("%c",i+int('a'));
	cout << endl;
	return 0;
}

