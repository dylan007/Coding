    #include <bits/stdc++.h>
     
    using namespace std;
     
    typedef unsigned long long int ll;
     
    int check(vector<ll> a,ll x)
    {
    	if(x==0 || x==1)
    		return 1;
    	int flag=0;
    	int curr=1,up=1;
    	for(int i=0;i<a.size();i++)
    	{
    		//cout << curr << " ";
    		if(a[i]<curr)
    		{
    			curr=a[i];
    			up=1;
    			curr += up;
    		}
    		else if(curr==1 && up<0)
    			return 1;
    		else if(curr==x)
    		{
    			up=-1;
    			curr += up;
    		} 
    		else
    			curr += up;
    	}
    	//cout << endl;
    	if(curr==0 && up<0)
    		return 1;
    	return 0;
    }
     
    int solve(vector<ll> a,ll low,ll high)
    {
    	if(low>high)
    		return 0;
    	ll mid = (low+high)/2;
    	//cout << mid << endl;
    	int f1,f2,f3;
    	f1 = check(a,mid);
    	f2 = check(a,mid-1);
    	f3 = check(a,mid+1);
    	//cout << f1 << " " << mid << " " << f2 << " " << f3  << endl;
    	if(f1 && f2 && !f3)
    	{
    		//cout << mid << endl;
    		return mid*mid;
    	}
    	else if(!f1)
    		return solve(a,low,mid-1);
    	else
    		return solve(a,mid+1,high);
    }
     
    int main()
    {
    	ll T;
    	cin >> T;
    	while(T--)
    	{
    		//cout << endl;
    		ll n;
    		cin >> n;
    		vector<ll> a;
    		ll x,m=0,sum=0;
    		for(int i=0;i<n;i++)
    		{
    			cin >> x;
    			a.push_back(x);
    			m = max(m,x);
    			sum += x;
    		}
    		//cout << check(a,3) << endl;
    		cout << sum - solve(a,1,m) << endl;
    	}
    } 
