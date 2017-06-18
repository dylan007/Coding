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
	int n;
	cin >> n;
	int x;
	int sum=0;
	for(int i=0;i<n;i++)
	{
		cin >> x;
		sum += x;
	}
	int y;
	int m;
	cin >> m;
	int ans=0,flag=0;
	while(m--)
	{
		cin >> x >> y;
		if(!flag && x>sum)
		{
			ans = x;
			flag=1;
		}
		else if(!flag && x<=sum && y>=sum)
		{
			ans = sum;
			flag=1;
		}
	}
	if(flag)
		cout << ans << endl;
	else
		cout << "-1" << endl;
	return 0;
}

