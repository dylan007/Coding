//Shounak Dey
#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define PB push_back
#define MK make_pair 
#define SZ(a) (int)(sizeof(a))
#define F first
#define S second
#define REP(i,a,b) for(int i=a;i<b;i++)
#define READ(n) scanf("%d",&n)
#define READL(n) scanf("%lld",&n)
#define SORTV(a) sort(a.begin(),a.end())
#define TESTCASE int Test;cin >> Test;while(Test--)

int substring(string a,string b)
{
	string temp;
	if(a.length()<b.length())//makes a the larger string
	{
		temp = a;
		a = b;
		b = temp;
	}//find if b is a subsequence of a 
//	cout << a << " " << b << endl;
	int al=a.length(),bl=b.length();
	int flag=0,curr=0;
	for(int i=0;i<al;i++)
	{
		if(curr==bl)
		{
			flag=1;
			break;
		}
		if(a[i]==b[curr])
			curr++;
	}
	if(curr==bl)
		flag=1;
	return flag;
}

int main()
{
	TESTCASE
	{
		string a,b;
		cin >> a >> b;
		if(substring(a,b))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}

