//Shounak Dey
#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define PB push_back
#define MK make_pair 

int main()
{
	string n;
	cin >> n;
	vector<int> ans;
	while(1)
	{
		int x=0;
		int flag=0;
		for(int i=0;i<n.length();i++)
		{
			if(n[i]-'0'>0)
			{
				x = x*10+1;
				n[i] -= 1;
				flag=1;
			}
			else
				x = x*10;
		}
		if(!flag)
			break;
		ans.PB(x);
	}
	cout << ans.size() << endl;
	for(int i=0;i<ans.size();i++)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}

