#include<bits/stdc++.h>

using namespace std;

void mul(int b[2][2],int x[2][2])
{
	int ans[2][2];
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			ans[i][j] = 0;
			for(int k=0;k<2;k++)
				ans[i][j] += b[i][k]*x[k][j];
		}
	}
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
			x[i][j] = ans[i][j];
	}
}


void copy(int b[2][2],int x[2][2])
{
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
			x[i][j] = b[i][j];
	}
}

void fast_expo(int b[2][2],int x)
{
	if(x==1)
		return;
	if(x%2 == 0)
	{
		mul(b,b);
		fast_expo(b,x/2);
	}
	else
	{
		int y[2][2];
		copy(b,y);
		fast_expo(b,x-1);
		mul(y,b);
	}
}

void print(int b[2][2])
{
	cout << b[0][0] << " " << b[0][1] << endl << b[1][0] << " " << b[1][1] << endl;
}

int main()
{
	int b[2][2] = {6,-4,1,0};
	int x[2][2];
	for(int i=1;i<=100;i++)
	{
		cout << i << endl;
		copy(b,x);
		fast_expo(x,i);
		print(x);
	}
	return 0;
}