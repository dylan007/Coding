#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,k,l,c,d,p,nl,np;
	scanf("%d%d%d%d%d%d%d%d",&n,&k,&l,&c,&d,&p,&nl,&np);
	nl = (k*l)/nl;
	np = p/np;
	c = c*d;
	int min;
	min = nl;
	min = min<np?min:np;
	min = min<c?min:c;
	//printf("%d %d %d\n",nl,c,np);
	/*if((nl<np)&&(nl<c))
		printf("%d\n",(nl/n));
	else if((np<nl)&&(np<c))
		printf("%d\n",(np/n));
	else if((c<nl)&&(c<np))
		printf("%d\n",(c/n));*/
	printf("%d\n",min/n);
	return 0;
}
