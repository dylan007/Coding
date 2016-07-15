/*
 * =====================================================================================
 *
 *       Filename:  gotyandtheplay.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Saturday 12 December 2015 11:11:54  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shounak Dey (), dylandey1996@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include<bits/stdc++.h>

using namespace std;

typedef struct node
{
	int data;
	struct node *left,*right;
}node;

node *head;

int main()
{
	int n,m,q;
	cin >> n >> m >> q;
	head = (node *)malloc(sizeof(node));
	head->data = 0;
	head-left = head->right = NULL;

	return 0;
}
