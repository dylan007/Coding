#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int n;
int a[100];
int bin[100];

void binary(int N)
{
	int top=0;
	printf("{");
	while(top<n && N>0)
	{
		if(N%2==1)
			printf("%d ",a[top]);
		N=N/2;
		top++;
	}
	printf("}\n");
}

int power(int N)
{
	if(N==(pow(2,n)))
		return;
	else
		binary(N);
	power(N+1);
}

int main()
{	
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	power(0);
	return 0;
}
