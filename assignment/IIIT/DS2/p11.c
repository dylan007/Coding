#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	long long int n;
	scanf("%lld",&n);
	while(n>0)
	{
		long long int a[n];
		long long int stack[2*n];
		long long int top=0;
		long long int max=0,temp,area,i=0;
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		i=0;
		while(i<n)
		{
			if(top==0 || (a[stack[top-1]] <= a[i]))
				stack[top++] = i++;
			else
			{
				temp = stack[top-1];
				top--;
				area = a[temp] * ((top==0)?i:(i-stack[top-1]-1));
				max = max<area?area:max;
			}
		}
		while(top>0)
		{
			temp = stack[top-1];
			top--;
			area = a[temp] * ((top==0)?i:(i-stack[top-1]-1));
			max = max<area?area:max;
		}
		printf("%lld\n",max);
		scanf("%lld",&n);
	}
	return 0;
}
