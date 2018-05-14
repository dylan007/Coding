#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int cmpfunc(const void *a,const void *b)
{
	return *(int *)b - *(int *)a;
}

int main()
{
	int n;
	cin >> n;
	int x,c1=0,c2=0,a[n];
	for(int i=0;i<n;i++)
	{
		cin >> x;
		c1 += (x==100);
		c2 += (x==200);
		a[i]=x;
	}
	if((c1+ c2*2)%2 != 0) cout << "NO" << endl;
	else
	{
		qsort(a,n,sizeof(int),cmpfunc);
		int A=0,B=0;
		for(int i=0;i<n;i++)
		{
			if(B>A)
				A += a[i];
			else
				B += a[i];
		}
		if(A!=B)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	return 0;
}
