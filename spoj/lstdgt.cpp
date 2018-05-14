#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
#define read(n) scanf("%llu",&n)
#define TEST int Test;cin >> Test;while(Test--)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

ull modx(string b,ull x)
{
	ull ans=0;
	for(int i=0;i<b.length();i++)
	{
		ans = (ans*10 + (int(b[i])-'0'))%x;
	}
	return ans;
}

int main()
{
	map<int,vector<int> >pows={{1,{1}},{2,{2,4,8,6}},{3,{3,9,7,1}},{4,{4,6}},{5,{5}},{6,{6}},{7,{7,9,3,1}},{8,{8,4,2,6}},{9,{9,1}},{0,{0}}
	};	
	TEST
	{
		string a,b;
		cin >> a >> b;
		ull x;
		x = a[a.length()-1]-'0';
		if(x==0)
			cout << "0" << endl;
		else if(b=="0")
			cout << "1" << endl;
		else
		{
			int l=pows[x].size();
			l = modx(b,l);
			if(l==0)
				l = pows[x].size()-1;
			else
				l--;
			cout << pows[x][l] << endl;
		}
	}
	return 0;
}

