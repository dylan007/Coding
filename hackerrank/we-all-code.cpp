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
	ull n;
	cin >> n;
	ull arr[n];
	for(int i=0;i<n;i++) cin >> arr[i];
	vector< pair<ull,ll> > stack;
	vector<ll> front;
	pair<ull,ll> temp;
	front.PB(-1);
	stack.PB(MK(arr[0],0));
	ull curr=arr[0];
	for(int i=1;i<n;i++)
	{
		curr = arr[i];
		ll x=-1;
		while(!stack.empty())
		{
			temp = stack.back();
			if(curr>temp.first)
				stack.pop_back();
			else
			{
				x = temp.second;
				break;
			}
		}
		stack.PB(MK(arr[i],i));
		front.PB(x+(x>=0 && x<n));
	}
	//for(int i=0;i<n;i++)
	//	cout << front[i] << endl;
	stack.clear();
	vector<ll> back;
	back.PB(-1);
	stack.PB(MK(arr[n-1],n-1));
	for(int i=(n-2);i>=0;i--)
	{
		curr = arr[i];
		ll x=-1;
		while(!stack.empty())
		{
			temp = stack.back();
			if(curr>temp.first)
				stack.pop_back();
			else
			{
				x = temp.second;
				break;
			}
		}
		stack.PB(MK(arr[i],i));
		back.PB(x+(x>=0 && x<n));
	}
	for(int i=0;i<n;i++)
		cout << front[i]+back[i] << " ";
	cout << endl;
	return 0;
}

