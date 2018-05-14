#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>

typedef struct pair
{
	int p;
	int q;
}pair;

int com(const void *a,const void *b)
{
	struct pair *p1=(struct pair *)a;
	struct pair *p2=(struct pair *)b;
	if(p1->p==p2->p)
		return p1->q - p2->q;
	else
		return p1->p - p2->p;
}

int main()
{
	int T;
	scanf("%d",&T);
	getchar();
	while(T--)
	{
		int i=0,n,ans=0,q,j,ctr,t;
		char C,s[100006];
		scanf("%s",s);
		int a=0,b=0,c=0;
		n=strlen(s);
		pair s2[n+1];
		s2[0].p = s2[0].q = 0;
		for(i=1;i<=n;i++)
		{
			a += (s[i-1]=='J');
			b += (s[i-1]=='M');
			c += (s[i-1]=='R');
			s2[i].p = b-a;
			s2[i].q = c-a;
		}
		qsort(s2,n+1,sizeof(pair),com);
		pair temp;
		int count=0,x=0;
		temp.p = temp.q = INT_MIN;
		for(i=0;i<=n;i++)
		{
			if(temp.p!=s2[i].p || temp.q!=s2[i].q)
			{
				temp.p = s2[i].p;
				temp.q = s2[i].q;
				x=0;
			}
			count+=x;
			x++;
		}
		printf("%d\n",count);
	}
	return 0;
} 
