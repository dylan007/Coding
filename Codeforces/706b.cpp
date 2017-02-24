#include<bits/stdc++.h>

using namespace std;

int binsearch(int x,int arr[],int start,int end)
{
	int mid = (start+end)/2;
	if(x == arr[mid])
		return mid + 1;
	else if(x<arr[mid] && x>arr[mid-1])
		return mid;
	else if(x>arr[mid] && x<arr[mid+1])
		return mid+1;
	else if(x>arr[mid])
		return binsearch(x,arr,mid,end);
	else if(x<arr[mid])
		return binsearch(x,arr,start,mid);
}	

int main()
{
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin >> arr[i];
	sort(arr,arr+n);
	int q;
	cin >> q;
	while(q--)
	{
		int x;
		cin >> x;
		cout << binsearch(x,arr,0,n) << endl;
	}
	return 0;
}
