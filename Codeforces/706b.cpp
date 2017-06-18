//Shounak Dey
#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define PB push_back
#define MK make_pair 
#define size(a) (int)(sizeof(a))

int binarySearch(vector<int> a, int item, int low, int high)
{
	if (high <= low)
		return (item > a[low])?  (low + 1): low;

	int mid = (low + high)/2;
	if(item == a[mid])
		return mid;
	if(item > a[mid])
		return binarySearch(a, item, mid+1, high);
	return binarySearch(a, item, low, mid-1);
}

int main()
{
	int n;
	cin >> n;
	vector<int> a;
	int x;
	for(int i=0;i<n;i++)
	{
		cin >> x;
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	int q;
	cin >> q;
	while(q--)
	{
		int y;
		cin >> y;
		int pos = binarySearch(a,y,0,n-1);
		cout << pos + (a[pos]==y) << endl;
	}
	return 0;
}

