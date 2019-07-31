#include <bits/stdc++.h>
 
// int cmpfunc(const void *a, const void *b)
// {
// 	return *(int *)a - *(int *)b;
// }
 
int main()
{
	unsigned int p,n,i,x,carcount=0,t,x1=0,x2=0,x3=0,x4=0;
	scanf("%u",&n);
	int arr[n];
	for(i=0;i<n;i++)
	{
		scanf("%u",&x);
		if(x==1)
			x1++;
		else if(x==2)
			x2++;
		else if(x==3)
			x3++;
		else if(x==4)
			x4++;
		arr[i] = x;
	}
	carcount += x4;
	carcount += x3;
	if(x1>=x3)
		x1 -= x3;
	else
		x1 = 0;
	carcount += x2/2;
	if(x2%2)
	{
		x2 = 1;
		carcount += 1;
		if(x1)
			x1 -= 1;
		if(x1)
			x1--;
	}
	else
		x2 =0;
	if(x1)
	{
		carcount += x1/4;
		if(x1%4)
			carcount++;
	}
 
	printf("%d\n",carcount);
 
	return 0;
}