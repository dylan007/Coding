/*
 * =====================================================================================
 *
 *       Filename:  template.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 21 May 2015 03:51:34  IST
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

int check(int c1[],int c2[])
{
	int flag=0;
	for(int i=0;i<26;i++)
		flag += (c2[i]>c1[i]);
	return (flag==0);
}

int main()
{
	string a;
	string b,c;
	cin >> a >> b >> c;
	int c1[26],c2[26],c3[26];
	memset(c1,0,sizeof(c1));
	memset(c2,0,sizeof(c2));
	memset(c3,0,sizeof(c3));
	for(int i=0;i<a.length();i++)
		c1[(int(a[i])-int('a'))]++;
	for(int i=0;i<b.length();i++)
		c2[(int(b[i])-int('a'))]++;
	for(int i=0;i<c.length();i++)
		c3[(int(c[i])-int('a'))]++;
	int C1,C2;
	C1 = check(c1,c2);
	C2 = check(c1,c3);
	//cout << C1 << " " << C2 << endl;
	if(C1 == 1)
	{
		cout << b;
		for(int i=0;i<26;i++)
			c1[i] -= c2[i];
		if(check(c1,c3) == 1)
		{
			cout << c;
			for(int i=0;i<26;i++)
				c1[i] -= c3[i];
		}
		for(int i=0;i<26;i++)
		{
			while(c1[i]--)
				cout << char(i+int('a'));
		}
		cout << endl;
	}
	else if(C2 == 1)
	{
		cout << c;
		for(int i=0;i<26;i++)
			c1[i] -= c3[i];
		if(check(c1,c2)==1)
		{
			cout << b;
			for(int i=0;i<26;i++)
				c1[i] -= c2[i];
		}
		for(int i=0;i<26;i++)
		{
			while(c1[i]--)
				cout << char(i+int('a'));
		}
		cout << endl;
	}
	return 0;
}
