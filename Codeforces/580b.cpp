/*
 * =====================================================================================
 *
 *       Filename:  580b.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Tuesday 22 September 2015 10:19:36  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shounak Dey (), dylandey1996@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll binsearch(ll start,ll end,vector< pair <ll,ll> > store,ll x,ll n)
{
	ll a,b,c,mid;
	mid = (start+end)/2;
	if(end<0)
		return 0;
	if(start>(n-1))
		return (n-1);
	a = store[start].first;
	b = store[end].first;
	c = store[mid].first;
	if(c == x)
		return mid - 1;
	else if(x > c)
		return binsearch(mid+1,end,store,x,n);
	else if(x<c && x>store[mid-1].first)
		return mid-1;
	else
		return binsearch(start,mid-1,store,x,n);
}

int main()
{
	ll n,d;
	cin >> n >> d;
	ll ans=0;
	vector<pair <ll,ll> > store;
	for(ll i =0;i<n;i++)
	{
		ll m,s;
		cin >> m >> s;
		pair<ll,ll> x;
		x.first = m;
		x.second = s;
		store.push_back(x);
	}
	sort(store.begin(),store.end());
	for(ll i=1;i<n;i++)
		store[i].second += store[i-1].second;
	ll max = 0;
	//for(ll i=0;i<n;i++)
	//	cout << store[i].first << " " << store[i].second << endl;
	/*for(ll i=0;i<n;i++)
	{
		ll ind;
		ind = binsearch(0,n-1,store,store[0].first+d,n);
		ll s;
	//	cout << store[i].first << " " << ind << " " <<  store[ind].first << endl;
		s = store[ind].second;
		cout << s << endl;
		max = s>max?s:max;
	}*/
	for(ll i=0;i<(n-1);i++)
	{
		ll ans=0;
		for(ll j=i+1;j<n;j++)
		{
			if(store[j].first-store[i].first>=d)
			{
				ans = store[j].second-(i!=0)*store[i-1].second;
				break;
			}
		}
		cout << ans << endl;
		max = max>ans?max:ans;
	}
	cout << max << endl;
	return 0;
}
