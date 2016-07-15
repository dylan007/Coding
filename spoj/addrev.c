#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int digit(int x)
{
	int count =0;
	while(x)
	{
		count++;
		x = x/10;
	}
	return count;
}

int arrayToInt(int arr[],int len)
{
	int k,i=0,ans=0,flag=0;
	while((arr[i]==0))
	{
		flag ++;
		i++;
	}
	for(i=0;i<len;i++)
	{
		k = pow(10,(i-flag));
		ans += arr[i] * k;
	}
	return ans;
}	

int main()
{
	int T,t;
	scanf("%d",&T);
	for(t=0;t<T;t++)
	{
		int x,i,y,dig=0;
		scanf("%d%d",&x,&y);
		if(x>y)
			dig = digit(x);
		else
			dig = digit(y);
		int a[dig],b[dig];
		for(i=(dig-1);i>=0;i--)
		{
			a[i] = x%10;
			b[i] = y%10;
			x = x/10;
			y = y/10;
		}
		//printf("%d\n",arrayToInt(a,dig));
		//printf("%d\n",arrayToInt(b,dig));
		int ans,flag=0;
		ans = arrayToInt(a,dig) + arrayToInt(b,dig);
		printf("ans = %d\n",ans);
	}
	return 0;
}
