/*
 * =====================================================================================
 *
 *       Filename:  set-queries.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Sunday 21 June 2015 10:28:05  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shounak Dey (), dylandey1996@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#define MAX 1000000009

typedef long long int ll;

typedef struct node
{
	ll data,start,end;
	struct node *left,*right;
}tree;

tree *head;

tree *create(ll S,ll E)
{
	tree *new;
	//printf("%lld %lld\n",S,E);
	new = (tree *)malloc(sizeof(tree));
	new->start = S;
	new->end = E;
	if(S!=E)
	{
		ll x = (S+E)/2;
		new->left = create(S,x);
		new->right = create(x+1,E);
	}
	else
		new->left = new->right = NULL;
	new->data = 0;
	return new;
}

tree *update(ll index,ll t,tree *H)
{
	if(H == NULL)
		return NULL;
	if((index < H->start) || (index > H->end))
		return H;
	H->data += t;
	H->left = update(index,t,H->left);
	H->right = update(index,t,H->right);
	return H;
}

void update_set(ll set[],ll t,ll size)
{
	ll i;
	for(i=0;i<size;i++)
		head = update(set[i],t,head);
	return;
}

ll get_elem(ll x,tree *H)
{
	if(H->start==H->end && H->start==x)
		return H->data;
	ll mid;
	mid = (H->start + H->end)/2;
	if(x<=mid)
		return get_elem(x,H->left);
	else
		return get_elem(x,H->right);
}

ll sum_set(ll set[],ll size)
{
	ll i;
	ll sum=0;
	for(i=0;i<size;i++)
		sum += get_elem(set[i],head);
	return sum;
}

ll get_sum(ll S,ll E,tree *H,ll sum)
{
	if(S == H->start  && E == H->end)
		return H->data+sum;
	if(S == E)
	{
		ll mid = (H->start + H->end)/2;
		if(S <= mid)
			sum = get_sum(S,S,H->left,sum);
		else
			sum = get_sum(E,E,H->right,sum);
	}
	else
	{
		ll mid = (H->start + H->end)/2;
		if(S <= mid)
			sum = get_sum(S,mid,H->left,sum);
		if(E > mid)
			sum = get_sum(mid+1,E,H->right,sum);
	}
	printf("%lld %lld %lld\n",S,E,sum);
	return sum;
}

void print(tree *H)
{
	if(H == NULL)
		return;
	print(H->left);
	printf("%lld %lld %lld\n",H->data,H->start,H->end);
	print(H->right);
	return;
}

int main()
{
	ll n,s,m;
	scanf("%lld %lld %lld",&n,&s,&m);
	head = create(1,n);
	ll i;
	ll sets[s][100000];
	ll size[s];
	//print(head);
	//printf("%lld\n",(ll)(sizeof(sets)));
	for(i=0;i<s;i++)
	{
		ll x;
		scanf("%lld",&x);
		size[i] = x;
		//printf("x= %lld i = %lld size=%lld\n",x,i,(ll)(sizeof(sets[i])));
		ll y,j;
		for(j=0;j<x;j++)
			scanf("%lld",&sets[i][j]);
	}
	for(i=0;i<m;i++)
	{
		ll c,a,l,r,t,j;
		scanf("%lld",&c);
		switch(c)
		{
			case 1:
				scanf("%lld %lld",&a,&t);
				update_set(sets[a-1],t,size[a-1]);
				//print(head);
				//printf("\n\n\n");
				break;
			case 2:
				scanf("%lld",&a);
				printf("%lld\n",(sum_set(sets[a-1],size[a-1])%MAX));
				break;
			case 3:
				scanf("%lld %lld %lld",&l,&r,&t);
				for(j=l;j<=r;j++)
					head = update(j,t,head);
				//print(head);
				//printf("\n\n\n");
				break;
			case 4:
				scanf("%lld %lld ",&l,&r);
				ll sum =0;
				//= get_sum(l,r,head,0);
				for(j=l;j<=r;j++)
					sum += get_elem(j,head);
				sum = sum%MAX;
				printf("%lld\n",sum);
				break;
		}
	}
	return 0;
}
