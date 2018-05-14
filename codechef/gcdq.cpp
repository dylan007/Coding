#include<iostream>
#include<stdio.h>

using namespace std;

int gcd(int a,int b)
{
	return (b!=0)?gcd(b,a%b):a;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,q;
		scanf("%d %d",&n,&q);
		int a[n];
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		int l,r;
		int ans=0;
		while(q--)
		{
			scanf("%d %d",&l,&r);
			l--;
			r--;
			ans=-1;
			for(int i=0;i<n;i++)
			{
				if(i<l || i>r)
				{
					if(ans<0)
						ans = a[i];
					else
						ans = gcd(ans,a[i]);
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
