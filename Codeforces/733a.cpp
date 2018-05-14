//Shounak Dey
#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define PB push_back
#define MK make_pair 

int check(string a,int i)
{
	if(a[i]=='A' || a[i]=='E' || a[i]=='I' || a[i]=='O' || a[i]=='U' || a[i]=='Y')
		return 1;
	return 0;
}

int main()
{	
	string a;
	cin >> a;
	vector<int> pos;
	for(int i=0;i<a.length();i++)
	{
		if(check(a,i))
			pos.PB(i+1);
	}
	if(pos.empty())
	{
		cout << a.length()+1 << endl;
		return 0;
	}
	int m=pos[0];
	for(int i=1;i<pos.size();i++)
		m = max(pos[i]-pos[i-1],m);
	m = max(m,int(a.length())+1-pos[pos.size()-1]);
	cout << m << endl;
	return 0;
}

