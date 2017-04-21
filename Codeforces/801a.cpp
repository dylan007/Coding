#include<bits/stdc++.h>

using namespace std;

int main()
{
	string a;
	cin >> a;
	int i,count=0,c2=0;
	for(i=0;i<a.length()-2;i++)
	{
		if(a[i]=='V' && a[i+1]=='K')
			count++;
		if(a[i]=='V' && a[i+1]=='V' && a[i+2]!='K')
			c2++;
	}
	count += (a[i]=='V' && a[i+1]=='K');
	if(a.length()<=2)
		c2 += (a[0]=='V' && a[1]=='V');
	cout << count + min(1,c2) << endl;
	return 0;
}

