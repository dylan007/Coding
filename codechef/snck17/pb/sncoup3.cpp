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
		ll n;
		cin >> n;
		string a,b;
		cin >> a >> b;
		//cout << a << endl << b << endl;
		ll c1=0,c2=0;
		for(int i=0;i<a.length();i++)
		{
			c1 += (a[i]=='*');
			c2 += (b[i]=='*');
		}
		if(c1==0)
			cout << max(ll(0),c2-1) << endl;
		else if(c2==0)
			cout << max(ll(0),c1-1) << endl;
		else
		{
			int count=1,x=0,y=0;
			for(int i=0;i<a.length();i++)
			{
				if(a[i]=='*')
				{
					if(x)
					{
						x=1;
						y=(b[i]=='*');
						count++;
					}
					else
					{
						x=1;
						if(y && (b[i]=='*'))
						{
							count++;
							x=1;
							y=1;
						}
					}
				}
				else if(b[i]=='*')
				{
					if(y)
					{
						y=1;
						x=(a[i]=='*');
						count++;
					}
					else
					{
						y=1;
						x|=(a[i]=='*');
					}
				}
				cout << x << " " << y << " " << count << endl;
			}
			cout << count << endl;
		}
	}
	return 0;
}

