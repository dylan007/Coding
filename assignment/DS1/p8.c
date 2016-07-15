#include<stdio.h>
#define ll long long
#define mod 1000000007
ll nofsol(ll x,ll upper,int n)
{
	int temp=0;
	if(x<=upper%n)
		temp=1;
	return (upper/n + temp);
}


ll solve(ll a,ll b,ll c,ll upper,int n)
{
	ll ans=0;
	ans=((((nofsol(a,upper,n)%mod)*(nofsol(b,upper,n)%mod))%mod)*(nofsol(c,upper,n)%mod))%mod;
	return ans;
}

ll expo(int a,ll b,int m)
{
	ll r=0;
	if(b==0)
		return 1;
	r = expo(a,b/2,m);
	r = (r*r)%m;
	if(b%2)
		r = (r*a)%m;
	return r;
}

int main()
{
	int t,n,m,temp,i,j,k;
	ll upper,d,a[41],ans;
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%lld%lld%d%d",&upper,&d,&m,&n);
		for(i=0;i<n;i++)
		{
			a[i]=expo(i,d,n);
		}
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				for(k=0;k<n;k++)
					if(((a[i]+a[j]+a[k])%n)==m)
					{
						ans+=solve(i,j,k,upper,n);
						ans%=mod;
					}
		printf("%lld\n",ans);
	}
	return 0;
}

