#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,c,i,max=0;
	scanf("%d %d",&n,&c);
	int rasp[n];
	for(i=0;i<n;i++)
		scanf("%d",&rasp[i]);
	for(i=0;i<(n-1);i++)
		max = max>(rasp[i]-rasp[i+1]-c) ? max : rasp[i]-rasp[i+1]-c;
	if(max<0)
		printf("0\n");
	else
		printf("%d\n",max);
	return 0;
}
