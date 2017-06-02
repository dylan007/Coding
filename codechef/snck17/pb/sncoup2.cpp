//Shounak Dey
#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define push_back PB
#define make_pair MK
#define size(a) (int)(sizeof(a))

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		string a,b;
		cin >> a >> b;
		//cout << a << endl << b << endl;
		vector<int> h(a.length(),0);
		for(int i=0;i<a.length();i++)
			h[i] = ((a[i]=='*') || (b[i]=='*'));
		int count=0,curr=0;
		for(int i=0;i<a.length();i++)
			count |= ((a[i]=='*') && (b[i]=='*'));
		//for(int i=0;i<a.length();i++)
		//	cout << h[i] << " ";
		//cout << endl;
		//cout << count << endl;
		for(int i=0;i<a.length();i++)
		{
			if(h[i]==0)
			{
				count += max(0,curr-1);
				curr=0;
			}
			else
				curr++;
			//cout << curr << " ";
			//count += (a[i]=='*' || b[i]=='*');
		}
		count += max(0,curr-1);
		cout << count << endl;
	}
	return 0;
}

