#include<bits/stdc++.h>

using namespace std;

void so(vector<int> &a,int n)
{
	for(int i=1;i<n;i++)
	{
		int j=i-1,key = a[i];
		while(j>=0 && a[j]>key)
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
	}
}

int main()
{
	int n,x;
	cin >> n;
	vector<int> arr;
	for(int i=0;i<n;i++)
	{
		cin >> x;
		arr.push_back(x);
	}
	so(arr,n);
	for(int i=0;i<n;i++)
			cout << arr[i] << " ";
	cout << endl;
	return 0;
}

