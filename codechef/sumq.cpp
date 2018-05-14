//Shounak Dey
#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define push_back PB
#define make_pair MK
#define size(a) (int)(sizeof(a))
#define MOD 1000000007

ull bs(ull a[], ull item, ull low, ull high)
{
	if (high <= low)
    	return (item > a[low])?  (low + 1): low;
	int mid = (low + high)/2;
	if(item == a[mid])
		return mid;
	if(item > a[mid])
		return bs(a, item, mid+1, high);
	return bs(a, item, low, mid-1);
}

ull ls(ull a[],ull item, ull low, ull high)
{
	while(low<=high)
	{
		if(item<a[low])
			return low-1;
		low++;
	}
	return high;
}

ull mul(ull a,ull b,ull c)
{
	return ((a%MOD)*(b%MOD)*(c%MOD));
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		ull p,q,r;
		cin >> p >> q >> r;
		ull a[p],b[q],c[r],x[p],y[r];
		for(int i=0;i<p;i++)
			cin >> a[i];
		sort(a,a+p);
		for(int i=0;i<p;i++)
		{
			if(i==0)
				x[i]=a[i];
			else
				x[i] = x[i-1]+a[i];
		}
		for(int i=0;i<q;i++)
			cin >> b[i];
		for(int i=0;i<r;i++)
			cin >> c[i];
		sort(c,c+r);
		for(int i=0;i<r;i++)
		{
			if(i==0)
				y[i]=c[i];
			else
				y[i] = y[i-1]+c[i];
		}
		ull ans=0;
		for(int i=0;i<q;i++)
		{
			int c1,c2;
			c1 = ls(a,b[i],0,p-1);
			c2 = ls(c,b[i],0,r-1);
			/*while(c1<p)
			{
				if(a[c1]!=b[i])
					break;
				c1++;
			}
			while(c2<p)
			{
				if(c[c2]!=b[i])
					break;
				c2++;
			}
			c1 -= a[c1]>b[i];
			c2 -= c[c2]>b[i];
			*/ull s1=0,s2=0;
			s1 = c1>=0?x[c1]:0;
			s2 = c2>=0?y[c2]:0;
			c1++;
			c2++;
			cout << s1 << " " << s2 << " " << c1 << " " << c2 << endl; 
			ans += (mul(s1,s2,1)+mul(s1,c2,b[i])+mul(s2,c1,b[i])+mul(c1,c2,b[i]*b[i]))%MOD;
		}
		cout << ans%MOD << endl;
	}
	return 0;
}

