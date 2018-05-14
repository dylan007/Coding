/*
 * =====================================================================================
 *
 *       Filename:  sarray.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 09 April 2015 07:43:51  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shounak Dey (), dylandey1996@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include<bits/stdc++.h>
#include<cstring>

using namespace std;

typedef struct elem
{	
	char *c;
	int index;
}elem;

int cmpfunc(elem elem1,elem elem2)
{
	return strcmp(elem1.c,elem2.c) < 0 ? 1 : 0;
}

void suffix(char *inp,int len)
{
	int i;
	elem suff[len];
	for(i=0;i<len;i++)
	{	
		suff[i].c = inp+i;
		suff[i].index = i;
	}
	sort(suff,suff+len,cmpfunc);
	for(int i=0;i<len;i++)
		cout << suff[i].index << endl;
}	

int main()
{
	char inp[100000];
	cin >> inp;
	elem *arr;
	suffix(inp,strlen(inp));
	//for(int i=0;i<strlen(inp);i++)
	//	cout << arr[i].index << endl;
	return 0;
}
