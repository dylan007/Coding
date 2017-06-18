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
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin >> arr[i];
	if(n==1)
		cout << "yes\n1 1" << endl;
	else
	{
		int up=(arr[1]>arr[0]);
		int count=0,ind=0;
		for(int i=1;i<(n-1);i++)
		{
			if(up)
			{
				if(arr[i+1]<arr[i])
				{
					up=1;
					count++;
				}
			}
			else
			{
				if(arr[i+1]>arr[i])
				{
					up=0;
					count++;
				}
			}
		}
		if(count>1)
			cout << "no" << endl;
		else
		{
			
		}
	}
	return 0;
}

