//Shounak Dey
#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define PB push_back
#define MK make_pair 
#define size(a) (int)(sizeof(a))

int main()
{
	string a;
	cin >> a;
	int flag=0;
	for(int i=(a.length()/2);i<a.length();i++)
		flag += (a[i]!=a[a.length()-1-i]);
	if(flag==1 || (!flag && a.length()%2))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}

