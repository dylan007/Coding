#include<iostream>
#include<cmath>

using namespace std;

int f=0;
int a[15];

void next_perm(int n,int k)
{
	int i;
	for(i=(k-1);i>=0;i--)
	{
		if(a[i]<n) 
			break;
	}
	a[i]++;
	int j;
	for(j=i+1;j<k;j++)
		a[j] = a[i];
	if(a[0]==n && a[k-1]==n)
		f=1;
}


int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		a[i]=1;
	int count=1;
	while(f!=1)
	{
		count++;
		next_perm(n,n);
	}

	cout << count << endl;
	return 0;
}
