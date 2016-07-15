#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int gcd(int u,int v)
{
	(v!=0)?gcd(v,u%v):u;
}

int main()
{
	int x,t,a,b,da,db;
	scanf("%d %d %d %d %d %d",&x,&t,&a,&b,&da,&db);
	x = a+b-x;
	for()
	if(x%gcd(da,db) == 0 && (da/(gcd(da,db))<t && db/(gcd(da,db))<t))
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
