/*
 * =====================================================================================
 *
 *       Filename:  minmax.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Tuesday 15 December 2015 10:41:29  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shounak Dey (), dylandey1996@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int p,q,n;
int a[120];
int ans;

int min(int x)
{
	int i,ret=1000000000;
	for(i = 0;i<n;++i) 
		ret =(ret<(abs( x- a[i] ))?ret:abs(x-a[i]));
	return ret;
}

void limits(int x)
{
	if(x<p || x>q) return;
	if(min(x) > min(ans))
		ans = x;
}

int main() {

	scanf("%d",&n);
	int i,j;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	scanf("%d %d",&p,&q);
	ans = p;
	limits(p); 
	limits(q); 
	for(i=0;i<n;++i) 
	{
		for(j=i+1;j<n;++j) 
			limits( (a[i]+a[j])/2 );
	}
	printf("%d\n",ans);
	return 0;
}

