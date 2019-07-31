/*=======================
Author    : Shounak Dey
=======================	*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
	string a;
	cin >> a;
	vector<int> l(a.length(),-1);
	vector<int> r(a.length(),-1);
	int curr=-1;
	for(int i=0;i<a.length();i++){
		if(a[i]=='X')
			curr=0;
		else if(a[i]=='Y')
			curr=1;
		l[i]=curr;
	}
	curr=-1;
	int i=a.length()-1;
	while(i>=0){
		if(a[i]=='X')
			curr=0;
		else if(a[i]=='Y')
			curr=1;
		r[i]=curr;
		i--;
	}
	int x=0,y=0;
	for(i=0;i<a.length();i++){
		if(a[i]=='X')
			x++;
		else if(a[i]=='Y')
			y++;
		else{
			if((l[i]!=-1) && (l[i]==r[i])){
				if(l[i])
					y++;
				else
					x++;
			}
		}
	}
	cout << x << " " << y << endl;
	return 0;
}

