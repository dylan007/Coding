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
		string s;
		cin >> s;
		int count=0,a=0,m=0;
		int n = s.length();
		for(int i=0;i<n;i++)
			a += s[i]=='s';
		m = n-a;
		vector<int> v(n,0);
		for(int i=0;i<n;i++)
		{
			if(s[i]=='m')
			{
				if(i==0)
				{
					count += (s[i+1]=='s')*(!v[i+1]);
					v[i]=1;
					v[i+1]=1;
				}
				else if(i==(n-1))
				{
					count += (s[i-1]=='s')*(!v[i-1]);
					v[i]=1;
					v[i-1]=1;
				}
				else
				{
					if(s[i-1]=='s' && !v[i-1])
					{
						count++;
						v[i-1]=1;
					}
					else if(s[i+1]=='s' && !v[i+1])
					{
						count++;
						v[i+1]=1;
					}
					v[i]=1;
				}	
			}
		}
		a -= count;
		if(m>a)
			cout << "mongooses" << endl;
		else if(m<a)
			cout << "snakes" << endl;
		else
			cout << "tie" << endl;
	}
	return 0;
}

