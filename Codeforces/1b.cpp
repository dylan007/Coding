//Shounak Dey
#include<bits/stdc++.h>
#include<string>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define PB push_back
#define MK make_pair 

int isalpha(string a,int i)
{
	if(int(a[i])>=65 && int(a[i])<=90)
		return 1;
	return 0;
}

int check(string a)
{
	for(int i=1;i<a.length();i++)
	{
		if(a[i]=='C')
		{
			if(!isalpha(a,i-1) && !isalpha(a,i+1))
				return 1;
		}
	}
	return 0;
}

string conv1(string a)
{
	int x=0,y=0;
	int i=1;
	for(i=1;i<a.length();i++)
	{
		if(isalpha(a,i))
			break;
		x = x*10 + a[i]-'0';
	}
	i++;
	while(i<a.length())
		y = y*10 + a[i++]-'0';
	cout << x << " " << y << endl;
	return a;
}

string conv2(string a)
{
	return a;
}

int main()
{	
	int T;
	cin >> T;
	while(T--)
	{
		string a;
		cin >> a;
		if(check(a))
			cout << conv1(a) << endl;
		else
			cout << conv2(a) << endl;
	}
	return 0;
}

