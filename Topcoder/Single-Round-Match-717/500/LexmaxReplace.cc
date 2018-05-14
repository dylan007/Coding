//Shounak Dey
#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
class LexmaxReplace
{
public:
	string get(string s, string t)
	{
		sort(t.begin(),t.end());
		cout << t << endl;
		for(int i=(t.length()-1);i>=0;i--)
		{
			int flag=0;
			for(int j=0;j<s.length();j++)
			{
				if(int(s[j])<int(t[i]))
				{
					s[j] = t[i];
					flag=1;
					break;
				}
			}
			if(!flag)
				break;
		}
		return s;
	}
};

