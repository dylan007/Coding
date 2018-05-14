/*
 * =====================================================================================
 *
 *       Filename:  kdatzero.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Friday 15 May 2015 10:20:19  IST
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

int power2(int x)
{
	int c2=0;
	while(x%2==0 && x>1)
	{
		c2++;
		x/=2;
	}
	return c2;
}

int power5(int x)
{
	int c5=0;
	while(x%5==0 && x>1)
	{
		c5++;
		x/=5;
	}
	return c5;
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int n,q,x;
		cin >> n >> q;
		int two[n];
		int five[n];
		two[0]=0;
		five[0] = 0;
		for(int i=0;i<n;i++)
		{
			cin >> x;
			//cout << x << " ";
			two[i] = power2(x) + two[i-(i>0)];
			five[i] = power5(x) + five[i-(i>0)];
		}
		//cout << endl;
		/*for(int i=0;i<n;i++)
			cout << two[i] << " ";
		cout << endl;
		for(int i=0;i<n;i++)
			cout << five[i] << " ";
		cout << endl;*/
		while(q--)
		{
			int c,l,r,v;
			cin >> c;
			if(c==1)
			{
				cin >> l >> r;
				int c2,c5;
				l--;
				r--;
				c2 = two[r]-two[l-1];
				c5 = five[r]-five[l-1];
				//cout << c2 << " " << c5 << " ";
				cout << min(c2,c5) << endl;
			}
			else
			{
				cin >> l >> r >> v;
				int c2,c5;
				c2 = power2(v);
				c5 = power5(v);
				l--;
				r--;
				for(int i=l;i<=r;i++)
				{
					two[i]+=c2;
					five[i]+=c5;
				}
			}
		}
	}
	return 0;
}
